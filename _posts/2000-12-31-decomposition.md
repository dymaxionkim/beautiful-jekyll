---
layout: post
published: true
title: decomposition
subtitle: 'Cubic Spline Interpolation with LU Decomposition in Univ., 2000'
date: '2000-12-31'
bigimg: /img/bigimg07.jpg
tags: software
---

## Summary
* C program & M code (Matlab) for Plotting
* LU Decomposition method
* Cubic Spline Interpolation
* for Motion Control Camera System

## Codes
* C Program

<script src="https://gist.github.com/dymaxionkim/2e6431935e6e6ff78e154f53932fb83d.js"></script>


* input.txt

```
19
0	0	0	0	0
.5	10	-10	5	90
1	20	-20	8	80
1.5	30	-30	9	70
2	60	-60	7	50
2.5	100	-100	5	30
3	90	-90	4	10
3.5	30	-30	3	-50
4	-100	100	5	-30
4.5	-80	80	2	-70
5	-90	90	1	-30
5.5	-50	50	0	-20
6	-30	30	0	-11
6.5	-15	15	0	-8
7	-5	5	10	-5
7.5	10	-10	20	10
8	15	-15	40	12
8.5	15	-15	70	24
9	15	-15	150	60
```

* output.txt

```
1       0.000        0.000        0.000        0.000        0.000
2       0.042        0.000        0.000        0.000        0.000
3       0.083        0.811       -0.811        0.454        9.731
4       0.125        1.623       -1.623        0.906       19.369
5       0.167        2.436       -2.436        1.355       28.819
6       0.208        3.253       -3.253        1.799       37.989
7       0.250        4.073       -4.073        2.238       46.784
8       0.292        4.898       -4.898        2.668       55.111
9       0.333        5.729       -5.729        3.089       62.876
10       0.375        6.566       -6.566        3.499       69.986
11       0.417        7.411       -7.411        3.897       76.347
12       0.458        8.264       -8.264        4.281       81.865
13       0.500        9.127       -9.127        4.649       86.448
14       0.542       10.000       -10.000        5.000       90.000
15       0.583       10.883       -10.883        5.333       92.465
16       0.625       11.773       -11.773        5.648       93.927
17       0.667       12.665       -12.665        5.946       94.507
18       0.708       13.554       -13.554        6.227       94.327
19       0.750       14.436       -14.436        6.494       93.507
20       0.792       15.305       -15.305        6.746       92.167
21       0.833       16.158       -16.158        6.984       90.430
22       0.875       16.988       -16.988        7.210       88.415
23       0.917       17.793       -17.793        7.423       86.244
24       0.958       18.566       -18.566        7.625       84.037
25       1.000       19.303       -19.303        7.817       81.915
26       1.042       20.000       -20.000        8.000       80.000
27       1.083       20.655       -20.655        8.173       78.384
28       1.125       21.283       -21.283        8.337       77.053
29       1.167       21.902       -21.902        8.487       75.964
30       1.208       22.529       -22.529        8.624       75.074
31       1.250       23.183       -23.183        8.745       74.340
32       1.292       23.880       -23.880        8.849       73.720
33       1.333       24.640       -24.640        8.933       73.171
34       1.375       25.481       -25.481        8.996       72.650
35       1.417       26.419       -26.419        9.036       72.116
36       1.458       27.473       -27.473        9.051       71.524
37       1.500       28.660       -28.660        9.040       70.833
38       1.542       30.000       -30.000        9.000       70.000
39       1.583       31.507       -31.507        8.931       68.992
40       1.625       33.185       -33.185        8.835       67.814
41       1.667       35.039       -35.039        8.714       66.481
42       1.708       37.070       -37.070        8.572       65.008
43       1.750       39.280       -39.280        8.411       63.411
44       1.792       41.673       -41.673        8.234       61.704
45       1.833       44.250       -44.250        8.044       59.902
46       1.875       47.015       -47.015        7.844       58.021
47       1.917       49.970       -49.970        7.637       56.075
48       1.958       53.118       -53.118        7.425       54.080
49       2.000       56.460       -56.460        7.212       52.050
50       2.042       60.000       -60.000        7.000       50.000
51       2.083       63.729       -63.729        6.792       47.946
52       2.125       67.595       -67.595        6.588       45.905
53       2.167       71.536       -71.536        6.391       43.894
54       2.208       75.489       -75.489        6.200       41.930
55       2.250       79.390       -79.390        6.016       40.031
56       2.292       83.178       -83.178        5.840       38.214
57       2.333       86.789       -86.789        5.673       36.496
58       2.375       90.161       -90.161        5.516       34.895
59       2.417       93.231       -93.231        5.369       33.427
60       2.458       95.936       -95.936        5.234       32.111
61       2.500       98.213       -98.213        5.110       30.963
62       2.542       100.000       -100.000        5.000       30.000
63       2.583       101.251       -101.251        4.903       29.224
64       2.625       101.989       -101.989        4.816       28.566
65       2.667       102.254       -102.254        4.739       27.943
66       2.708       102.087       -102.087        4.667       27.270
67       2.750       101.527       -101.527        4.598       26.464
68       2.792       100.615       -100.615        4.531       25.439
69       2.833       99.391       -99.391        4.462       24.112
70       2.875       97.896       -97.896        4.388       22.399
71       2.917       96.169       -96.169        4.308       20.216
72       2.958       94.250       -94.250        4.218       17.477
73       3.000       92.181       -92.181        4.116       14.100
74       3.042       90.000       -90.000        4.000       10.000
75       3.083       87.726       -87.726        3.868        5.136
76       3.125       85.282       -85.282        3.725       -0.354
77       3.167       82.572       -82.572        3.577       -6.290
78       3.208       79.498       -79.498        3.429       -12.492
79       3.250       75.960       -75.960        3.289       -18.779
80       3.292       71.861       -71.861        3.161       -24.971
81       3.333       67.104       -67.104        3.052       -30.886
82       3.375       61.589       -61.589        2.968       -36.344
83       3.417       55.219       -55.219        2.915       -41.166
84       3.458       47.896       -47.896        2.899       -45.169
85       3.500       39.523       -39.523        2.925       -48.174
86       3.542       30.000       -30.000        3.000       -50.000
87       3.583       19.293       -19.293        3.127       -50.533
88       3.625        7.621       -7.621        3.298       -49.929
89       3.667       -4.732        4.732        3.501       -48.407
90       3.708       -17.486       17.486        3.727       -46.191
91       3.750       -30.356       30.356        3.963       -43.500
92       3.792       -43.061       43.061        4.199       -40.557
93       3.833       -55.319       55.319        4.424       -37.584
94       3.875       -66.846       66.846        4.627       -34.800
95       3.917       -77.360       77.360        4.797       -32.429
96       3.958       -86.579       86.579        4.923       -30.691
97       4.000       -94.220       94.220        4.995       -29.807
98       4.042       -100.000       100.000        5.000       -30.000
99       4.083       -103.730       103.730        4.932       -31.417
100       4.125       -105.585       105.585        4.797       -33.913
101       4.167       -105.833       105.833        4.606       -37.268
102       4.208       -104.743       104.743        4.368       -41.263
103       4.250       -102.582       102.582        4.093       -45.680
104       4.292       -99.619       99.619        3.793       -50.299
105       4.333       -96.121       96.121        3.476       -54.902
106       4.375       -92.357       92.357        3.152       -59.269
107       4.417       -88.595       88.595        2.833       -63.182
108       4.458       -85.103       85.103        2.528       -66.420
109       4.500       -82.148       82.148        2.247       -68.766
110       4.542       -80.000       80.000        2.000       -70.000
111       4.583       -78.853       78.853        1.795       -69.968
112       4.625       -78.616       78.616        1.629       -68.773
113       4.667       -79.123       79.123        1.497       -66.585
114       4.708       -80.210       80.210        1.395       -63.572
115       4.750       -81.712       81.712        1.316       -59.903
116       4.792       -83.464       83.464        1.256       -55.746
117       4.833       -85.301       85.301        1.209       -51.269
118       4.875       -87.059       87.059        1.171       -46.642
119       4.917       -88.572       88.572        1.136       -42.033
120       4.958       -89.677       89.677        1.099       -37.611
121       5.000       -90.208       90.208        1.056       -33.543
122       5.042       -90.000       90.000        1.000       -30.000
123       5.083       -88.935       88.935        0.929       -27.109
124       5.125       -87.081       87.081        0.843       -24.837
125       5.167       -84.549       84.549        0.748       -23.110
126       5.208       -81.454       81.454        0.646       -21.855
127       5.250       -77.909       77.909        0.540       -20.999
128       5.292       -74.027       74.027        0.435       -20.468
129       5.333       -69.921       69.921        0.333       -20.189
130       5.375       -65.704       65.704        0.239       -20.089
131       5.417       -61.491       61.491        0.155       -20.093
132       5.458       -57.393       57.393        0.084       -20.128
133       5.500       -53.525       53.525        0.032       -20.122
134       5.542       -50.000       50.000        0.000       -20.000
135       5.583       -46.904       46.904       -0.009       -19.705
136       5.625       -44.219       44.219        0.002       -19.246
137       5.667       -41.900       41.900        0.026       -18.647
138       5.708       -39.900       39.900        0.059       -17.933
139       5.750       -38.176       38.176        0.095       -17.128
140       5.792       -36.681       36.681        0.129       -16.256
141       5.833       -35.371       35.371        0.156       -15.342
142       5.875       -34.199       34.199        0.171       -14.411
143       5.917       -33.122       33.122        0.168       -13.486
144       5.958       -32.093       32.093        0.142       -12.593
145       6.000       -31.068       31.068        0.088       -11.756
146       6.042       -30.000       30.000        0.000       -11.000
147       6.083       -28.856       28.856       -0.123       -10.343
148       6.125       -27.640       27.640       -0.271       -9.785
149       6.167       -26.368       26.368       -0.429       -9.316
150       6.208       -25.056       25.056       -0.584       -8.932
151       6.250       -23.720       23.720       -0.721       -8.623
152       6.292       -22.375       22.375       -0.826       -8.384
153       6.333       -21.037       21.037       -0.886       -8.207
154       6.375       -19.722       19.722       -0.885       -8.084
155       6.417       -18.445       18.445       -0.810       -8.010
156       6.458       -17.221       17.221       -0.647       -7.975
157       6.500       -16.068       16.068       -0.382       -7.975
158       6.542       -15.000       15.000       -0.000       -8.000
159       6.583       -14.028       14.028        0.507       -8.043
160       6.625       -13.139       13.139        1.129       -8.088
161       6.667       -12.316       12.316        1.848       -8.119
162       6.708       -11.542       11.542        2.648       -8.119
163       6.750       -10.799       10.799        3.513       -8.071
164       6.792       -10.070       10.070        4.427       -7.959
165       6.833       -9.337        9.337        5.372       -7.766
166       6.875       -8.582        8.582        6.332       -7.475
167       6.917       -7.789        7.789        7.292       -7.069
168       6.958       -6.939        6.939        8.234       -6.533
169       7.000       -6.015        6.015        9.142       -5.849
170       7.042       -5.000        5.000       10.000       -5.000
171       7.083       -3.883        3.883       10.796       -3.979
172       7.125       -2.676        2.676       11.543       -2.808
173       7.167       -1.399        1.399       12.256       -1.521
174       7.208       -0.073        0.073       12.954       -0.149
175       7.250        1.285       -1.285       13.652        1.275
176       7.292        2.653       -2.653       14.369        2.719
177       7.333        4.013       -4.013       15.121        4.151
178       7.375        5.345       -5.345       15.925        5.538
179       7.417        6.629       -6.629       16.797        6.849
180       7.458        7.846       -7.846       17.756        8.051
181       7.500        8.976       -8.976       18.818        9.112
182       7.542       10.000       -10.000       20.000       10.000
183       7.583       10.902       -10.902       21.313       10.692
184       7.625       11.688       -11.688       22.746       11.203
185       7.667       12.365       -12.365       24.283       11.560
186       7.708       12.942       -12.942       25.906       11.788
187       7.750       13.428       -13.428       27.599       11.911
188       7.792       13.831       -13.831       29.346       11.956
189       7.833       14.160       -14.160       31.128       11.948
190       7.875       14.424       -14.424       32.930       11.913
191       7.917       14.631       -14.631       34.735       11.874
192       7.958       14.791       -14.791       36.526       11.859
193       8.000       14.911       -14.911       38.287       11.893
194       8.042       15.000       -15.000       39.999       12.000
195       8.083       15.066       -15.066       41.659       12.204
196       8.125       15.113       -15.113       43.305       12.518
197       8.167       15.142       -15.142       44.986       12.952
198       8.208       15.156       -15.156       46.753       13.516
199       8.250       15.158       -15.158       48.656       14.222
200       8.292       15.148       -15.148       50.746       15.080
201       8.333       15.131       -15.131       53.072       16.100
202       8.375       15.108       -15.108       55.684       17.292
203       8.417       15.080       -15.080       58.633       18.668
204       8.458       15.052       -15.052       61.968       20.238
205       8.500       15.024       -15.024       65.740       22.011
206       8.542       15.000       -15.000       69.999       24.000
207       8.583       14.981       -14.981       74.795       26.213
208       8.625       14.970       -14.970       80.178       28.662
209       8.667       14.969       -14.969       86.197       31.358
210       8.708       14.980       -14.980       92.905       34.310
211       8.750       15.006       -15.006       100.349       37.529
212       8.792       15.049       -15.049       108.581       41.026
213       8.833       15.112       -15.112       117.650       44.811
214       8.875       15.195       -15.195       127.607       48.895
215       8.917       15.303       -15.303       138.502       53.288
216       8.958       15.437       -15.437       150.384       58.000
217       9.000       15.599       -15.599       163.305       63.043
```

* see_curve.m

```matlab
load output.txt

x=output(:,2);
y1=output(:,3);
y2=output(:,4);
y3=output(:,5);
y4=output(:,6);

plot(x,y1,'m.')
hold on
plot(x,y2,'c.')
plot(x,y3,'r.')
plot(x,y4,'.')
grid on

plot(x,y1)
plot(x,y2)
plot(x,y3)
plot(x,y4)
```


## Result
* Source Code : [Source](https://drive.google.com/open?id=0B3VzdmodvgcIUFNHUGhmUkRERTg)
* Report : [2000_LU_Decomposition.pdf](https://drive.google.com/open?id=0B3VzdmodvgcIM2lGRk5CMjFfckE)
