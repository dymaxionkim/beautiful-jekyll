---
layout: post
published: true
title: STEP2UNV_with_Salome_for_Elmer
bigimg: /img/bigimg37.jpg
subtitle: >-
  It's very boring to make mesh from STEP to UNV with Salome for Elmer.  This
  script may help to save my time.
date: '2017-09-12'
image: >-
  https://user-images.githubusercontent.com/12775748/30312408-54d6f296-97d4-11e7-8104-e5ee9b5d492d.png
tags: software
---
## Salome

* Mesh 생성 도구는 여러가지 다양하게 많지만, 결국에는 Salome를 사용하지 않을 수 없는 상황이 되곤 한다.
* 즉 다른 도구들에게 없는 부족함 없이, 필요한 거의 모든 기능을 제공해 주기 때문이다.
* 다만 Salome는 약간 개념이 특이한 점이 있어서, 형상을 그리거나 기타 조작을 할 때 어딘가에 필요한 기능이 분명 숨어는 있기는 하지만 그것을 직관적으로 찾아서 알아서 작업하기는 어렵다.  처음에는 매뉴얼 및 포럼 등을 이리저리 뒤져가면서 익혀가는 수 밖에 없는 것 같다.

## Salome to Elmer

* 실무적인 상황에서는, 보통 3D 모델링 데이타를 STEP 포멧으로 만들어서 시작하는 경우가 대부분이라고 볼 수 있다.
* 다행히 Salome는 STEP 포멧을 읽어들이고 조작하는데 비교적 안정적이기 때문에 그럭저럭 쓸만하다고 보인다.
* 여러개의 Parts로 구성된 Assembly STEP 파일을 한꺼번에 읽어들이고, 자동적으로 Group 분할 작업을 하고, Mesh를 생성한 다음, Elmer에서 읽어들일 수 있는 UNV 포멧으로 저장해 주는 작업을 자동화하고 싶다.
* 이때 Salome는 Python 기반의 Script 기능을 제공하므로, 이것을 이용하면 된다.

## First step

* Salome에서 일련의 작업을 수행한 후, hdf 파일을 저장하는 것과 별도로, `File - Dump Study`를 해서 py 파일로 저장해 주면, 작업한 모든 내역이 Python Script로 저장된다.  나중에 빈 Study 상태에서 `File - Load Study`해서 해당 py 파일을 로딩하면 그대로 실행되어 복원된다.
* 이때, py 파일을 원하는대로 적절히 수정해서 실행시키면 필요한 자동화 작업이 가능할 것이다.
* Salome에서 제공하는 Python Functions들은 [이곳](http://www.salome-platform.org/user-section)에서 매뉴얼을 뒤져가면서 참조하면 된다.

## step2unv

* 이런 과정을 거쳐 나름대로 만들어본 스크립트는 아래와 같다.

```python
# -*- coding: utf-8 -*-

#################################################
#
#   STEP2UNV for Elmer with Salome
#   V02
#
#   Data: 2017-09-12
#   Modifier : DymaxionKim
#
#   - Salome 8.2
#   - Import single STEP assembly file
#   - Excecute in CUI but not Salome GUI
#   - Only for STEP format
#   - Auto Group for each solids, subshape faces, intersect faces
#
#################################################

import sys
import salome
import os

salome.salome_init()
theStudy = salome.myStudy

import salome_notebook
notebook = salome_notebook.NoteBook(theStudy)

#tolerance = 1e-10	# max tolerance for identification of vertices

#################################################
## User Inputs
#################################################
# WORKING DIRECTORY
#print("\n" * 100)
print("----------------------------------------------------")
print("Input your working directory :")
DIRECTORY = raw_input()
sys.path.insert( 0, DIRECTORY)

# File Name
print("----------------------------------------------------")
print("Input your STEP File Name :")
FILENAME = raw_input()

# Mesh Parameters
print("----------------------------------------------------")
print("----- Mesh Parameters -----")
MinMeshSize = float(raw_input("MinMeshSize[m] : ")) # specify in m
MaxMeshSize = float(raw_input("MaxMeshSize[m] : ")) # specify in m
#MeshSecondOrder = float(raw_input("SetSecondOrder[0,1] : "))
MeshSecondOrder = 1
print("SetFiness ::: 0=VeryCoarse, 1=Coarse, 2=Moderate, 3=Fine, 4=VeryFine, 5=Custom")
MeshFineness = float(raw_input("SetFineness[0~5] : "))
if MeshFineness==5:
	MeshSegPerEdge = float(raw_input("  MeshSegPerEdge[ea] : "))
	MeshSegPerRadius = float(raw_input("  MeshSegPerRadius[ea] : "))
	MeshGrowthRate = float(raw_input("  MeshGrowthRate[0~1] : "))


#################################################
### GEOM component
#################################################
import GEOM
from salome.geom import geomBuilder
import math
import SALOMEDS


# New Study
geompy = geomBuilder.New(theStudy)

# Read STEP File
print("----------------------------------------------------")
print("----- Read STEP file ... ")
PARTS = []
ASSEMBLY = geompy.ImportSTEP(DIRECTORY+"/"+FILENAME, False, True)
PARTS = geompy.ExtractShapes(ASSEMBLY, geompy.ShapeType["SOLID"], True)
PARTITION = geompy.MakePartition(PARTS, [], [], [], geompy.ShapeType["SOLID"], 0, [], 0)
PARTS = geompy.ExtractShapes(PARTITION, geompy.ShapeType["SOLID"], True)


#################################################
# GROUP (VOLUMES of PARTS)
#################################################
GROUP_PARTS = []
ID_PARTS = []
for aPART in range(0,len(PARTS)):
	ID_PARTS.append(geompy.GetSubShapeID(PARTITION, PARTS[aPART]))
for aGROUP in range(0,len(PARTS)):
	GROUP_PARTS.append(geompy.CreateGroup(PARTITION, geompy.ShapeType["SOLID"]))
for aGROUP in range(0,len(PARTS)):
	geompy.AddObject(GROUP_PARTS[aGROUP], ID_PARTS[aGROUP])

# Add to Study
geompy.addToStudy( PARTITION, 'PARTITION' )
for aGROUP in range(0,len(GROUP_PARTS)):
	geompy.addToStudyInFather(PARTITION, GROUP_PARTS[aGROUP], 'PART{0}'.format(aGROUP+1) )


#################################################
# GROUP (FACES of PARTS)
#################################################
GROUP_FACES = []
for aGROUP in range(0,len(GROUP_PARTS)):
	FACES = []
	ID_FACES = []
	FACES = geompy.SubShapeAll(GROUP_PARTS[aGROUP], geompy.ShapeType["FACE"])
	for fGROUP in range(0,len(FACES)):
		ID_FACES.append(geompy.GetSubShapeID(PARTITION, FACES[fGROUP]))
	GROUP_FACES.append(geompy.CreateGroup(PARTITION, geompy.ShapeType["FACE"]))
	geompy.UnionIDs(GROUP_FACES[aGROUP], ID_FACES)

# Add to Study
for aGROUP in range(0,len(GROUP_PARTS)):
	geompy.addToStudyInFather(PARTITION, GROUP_FACES[aGROUP], 'FACE{0}'.format(aGROUP+1) )


#################################################
### SMESH component
#################################################
import  SMESH, SALOMEDS
from salome.smesh import smeshBuilder

# New Study
smesh = smeshBuilder.New(theStudy)

# New Mesh
MESH = smesh.Mesh(PARTITION)

# Parameters
NETGEN_2D3D = MESH.Tetrahedron(algo=smeshBuilder.NETGEN_1D2D3D)
NETGEN_Parameters = NETGEN_2D3D.Parameters()
NETGEN_Parameters.SetMinSize( MinMeshSize )
NETGEN_Parameters.SetMaxSize( MaxMeshSize )
NETGEN_Parameters.SetSecondOrder( int(MeshSecondOrder) )
# SetFiness ::: 0=VeryCoarse, 1=Coarse, 2=Moderate, 3=Fine, 4=VeryFine, 5=Custom
if MeshFineness!=5:
	NETGEN_Parameters.SetFineness( int(MeshFineness) )
if MeshFineness==5:
	NETGEN_Parameters.SetGrowthRate( MeshGrowthRate )
	NETGEN_Parameters.SetNbSegPerEdge( MeshSegPerEdge )
	NETGEN_Parameters.SetNbSegPerRadius( MeshSegPerRadius )
	NETGEN_Parameters.SetUseSurfaceCurvature( 1 ) # 0 or 1
NETGEN_Parameters.SetQuadAllowed( 0 )
NETGEN_Parameters.SetOptimize( 1 )
NETGEN_Parameters.SetFuseEdges( 1 )


#################################################
# GROUP (VOLUMES of PARTS)
#################################################
MGROUP_PARTS = []
for aGROUP in range(0,len(GROUP_PARTS)):
	MGROUP_PARTS.append( MESH.GroupOnGeom(GROUP_PARTS[aGROUP], 'PART{0}'.format(aGROUP+1), SMESH.VOLUME) )


#################################################
# GROUP (FACES of PARTS)
#################################################
MGROUP_FACES = []
for aGROUP in range(0,len(GROUP_PARTS)):
	MGROUP_FACES.append( MESH.GroupOnGeom(GROUP_FACES[aGROUP], 'FACE{0}'.format(aGROUP+1), SMESH.FACE) )


#################################################
# Make MESH
#################################################
print("----------------------------------------------------")
print("----- Mesh Computing ... ")
isDone = MESH.Compute()


#################################################
# GROUP (INTERSECT FACES of PARTS)
#################################################
MGROUP_INTERSECTS = []
for fGROUP in range(0,len(MGROUP_FACES)):
	for fGROUP2 in range(fGROUP+1,len(MGROUP_FACES)):
		if fGROUP!=fGROUP2:
			aCriteria = []
			aCriterion = smesh.GetCriterion(SMESH.FACE,SMESH.FT_BelongToMeshGroup,SMESH.FT_Undefined,MGROUP_FACES[fGROUP],SMESH.FT_Undefined,SMESH.FT_LogicalAND)
			aCriteria.append(aCriterion)
			aCriterion = smesh.GetCriterion(SMESH.FACE,SMESH.FT_BelongToMeshGroup,SMESH.FT_Undefined,MGROUP_FACES[fGROUP2])
			aCriteria.append(aCriterion)
			aFilter = smesh.GetFilterFromCriteria(aCriteria)
			aFilter.SetMesh(MESH.GetMesh())
			info = []
			info = smesh.GetMeshInfo(aFilter)
			if info.values()[10]: # Dictionary Key : Entity_Quad_Triangle
				MGROUP_INTERSECTS.append( MESH.GroupOnFilter( SMESH.FACE, 'INTERSECT{0}'.format(fGROUP+1), aFilter ) )


#################################################
# GROUP (CUT FACES of PARTS)
#################################################
MGROUP_CUTS = []
for fGROUP in range(0,len(MGROUP_FACES)):
	aCriteria = []
	aCriterion = smesh.GetCriterion(SMESH.FACE,SMESH.FT_BelongToMeshGroup,SMESH.FT_Undefined,MGROUP_FACES[fGROUP],SMESH.FT_Undefined,SMESH.FT_LogicalAND)
	aCriteria.append(aCriterion)
	for fGROUP2 in range(0,len(MGROUP_INTERSECTS)):
		aCriterion = smesh.GetCriterion(SMESH.FACE,SMESH.FT_BelongToMeshGroup,SMESH.FT_Undefined,MGROUP_INTERSECTS[fGROUP2],SMESH.FT_LogicalNOT)
		aCriteria.append(aCriterion)
	aFilter = smesh.GetFilterFromCriteria(aCriteria)
	aFilter.SetMesh(MESH.GetMesh())
	info = []
	info = smesh.GetMeshInfo(aFilter)
	if info!=smesh.GetMeshInfo(MGROUP_FACES[fGROUP]) and info.values()[10]:
		MGROUP_CUTS.append( MESH.GroupOnFilter( SMESH.FACE, 'CUT{0}'.format(fGROUP+1), aFilter ) )


#################################################
# Make UNV
#################################################
FILENAME_HEAD = os.path.splitext(FILENAME)[-2]
print("----------------------------------------------------")
print("----- Make UNV ... ")
try:
  MESH.ExportUNV( DIRECTORY+"/"+FILENAME_HEAD+".unv")
except:
  print 'ExportUNV() failed. Invalid file name?'


#################################################
# MESH Info
#################################################
print("----------------------------------------------------")
print "Information about mesh:" 
print "Number of nodes       : ", MESH.NbNodes()
print "Number of edges       : ", MESH.NbEdges()
print "Number of faces       : ", MESH.NbFaces()
print "          triangles   : ", MESH.NbTriangles()
print "          quadrangles : ", MESH.NbQuadrangles()
print "          polygons    : ", MESH.NbPolygons()
print "Number of volumes     : ", MESH.NbVolumes()
print "          tetrahedrons: ", MESH.NbTetras()
print "          hexahedrons : ", MESH.NbHexas()
print "          prisms      : ", MESH.NbPrisms()
print "          pyramids    : ", MESH.NbPyramids()
print "          polyhedrons : ", MESH.NbPolyhedrons() 
print("----------------------------------------------------")
print("----- FINISHED ! -----")


#################################################
# DISPLAY
#################################################
#if salome.sg.hasDesktop():
#  salome.sg.updateObjBrowser(True)


```

* 단, 이 Script는 `import os` 해서 `raw_input()` 같은 함수를 사용하고 있기 때문에, Salome GUI 상의 Python Console에서는 입력이 불가능하다. (아쉽게도 Salome에서 현재까지는 User input을 지원하지 않는다.)
* 그래서 Salome GUI를 띄우는 것을 생략하고, 그냥 Bash Console 상에서 곧바로 실행하는 방식을 취했다.  실행용 쉘스크립트 파일은 아래와 같은 내용을 가진다.

```bash
#!/bin/bash
salome -t ~/.config/salome/step2unv/step2unv.py
exit 0
```

* 원본 및 사용설명서는 [Github 저장소](https://github.com/dymaxionkim/ElmerFEM_Examples/tree/master/20170911_Salome_Script_STEP2UNV)에서 관리한다.


## ETC

* 여러개의 부품으로 구성된 3D 모델을 STEP 포멧으로 만들어 두고, 그것을 이 프로그램을 이용하여 단숨에 UNV 파일로 변환시켜 작업시간을 단축시킬 수 있을 것이다.
* 다만, 몇 가지 제약사항이 있다고 봐야 한다.  어셈블리 관계가 너무 복잡하거나, 접촉면이 복잡한 관계로 구성되어 있을 경우에는 면 분할이 제대로 안될 확률이 높다(Tolerance 문제).  부품과 부품 사이에는, 면접촉은 되지만 서로간에 간섭(Volume Interference)이 있으면 에러가 난다.  그런 경우에 대해서는 아무런 분기를 시켜두지 않았기 때문이다.
* 접촉면은 자동적으로 별도의 Surface Group으로 형성되도록 해 놓았다.  그러나 역시 너무 관계가 복잡해지면 꼬일 확률이 있을 수 있다.  또 하나의 파트에 수백개의 파트가 달라붙어 있는 식이면 내부적으로 필터링하는데 시간이 굉장히 오래 걸릴 수 있다.
* 형상의 치수는 Mesh Parameter와 관련이 깊기 때문에, 제대로 Mesh가 생성되도록 하려면 Mesh Parameter를 잘 주는 것이 중요하다.  미터[m] 단위로 적절히 유의해서 입력하도록 한다.


## 122개의 파트로 구성된 어셈블리의 자동 매쉬 생성 예

* 파트수가 많기 때문에 생성시간이 상당히 걸리는 것을 확인.

![20170913_802x635](https://user-images.githubusercontent.com/12775748/30353205-904c11fe-985f-11e7-8ffb-47b3e0595bc2.png)

* 파트간의 접촉면(Intersect)을 별도의 면그룹(Surface group)으로 생성한 것을 확인.

![20170913_802x635](https://user-images.githubusercontent.com/12775748/30353349-4396c506-9860-11e7-895a-d9ddab504c1f.png)

