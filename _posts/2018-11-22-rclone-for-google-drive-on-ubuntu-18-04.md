---
layout: post
published: true
title: rclone for Google Drive on Ubuntu 18.04
bigimg: /img/bigimg43.jpg
date: '2018-11-22'
image: 'https://upload.wikimedia.org/wikipedia/commons/d/da/Google_Drive_logo.png'
tags: software
subtitle: 리눅스에 구글드라이브 마운팅하기
---

* Ubuntu 18.04부터 rclone이 apt 기본 패키지로 포함되어서, 간편하게 설치 가능하게 되었다.
* 기존 Ubuntu 16.04는 [이곳](https://rclone.org/downloads/) 참조.
* snap 패키지로는 설치해도 작동을 제대로 안하기 때문에 쓸모가 없는 것 같다.

## Install rclone

```bash
(py2) osboxes@ubuntu:~$ sudo apt install rclone
패키지 목록을 읽는 중입니다... 완료
의존성 트리를 만드는 중입니다       
상태 정보를 읽는 중입니다... 완료
다음 새 패키지를 설치할 것입니다:
  rclone
0개 업그레이드, 1개 새로 설치, 0개 제거 및 0개 업그레이드 안 함.
3,186 k바이트 아카이브를 받아야 합니다.
이 작업 후 12.6 M바이트의 디스크 공간을 더 사용하게 됩니다.
받기:1 http://kr.archive.ubuntu.com/ubuntu bionic/universe amd64 rclone amd64 1.36-3 [3,186 kB]
내려받기 3,186 k바이트, 소요시간 1초 (6,236 k바이트/초)
Selecting previously unselected package rclone.
(데이터베이스 읽는중 ...현재 437007개의 파일과 디렉터리가 설치되어 있습니다.)
Preparing to unpack .../rclone_1.36-3_amd64.deb ...
Unpacking rclone (1.36-3) ...
rclone (1.36-3) 설정하는 중입니다 ...
Processing triggers for man-db (2.8.3-2ubuntu0.1) ...
```

## Check Version

```bash
(py2) osboxes@ubuntu:~$ rclone version
2018/11/22 15:41:53 NOTICE: Config file "/home/osboxes/.config/rclone/rclone.conf" not found - using defaults
rclone v1.36
```

## Config

```bash
(py2) osboxes@ubuntu:~$ rclone config
2018/11/22 15:42:37 NOTICE: Config file "/home/osboxes/.config/rclone/rclone.conf" not found - using defaults
No remotes found - make a new one
n) New remote
r) Rename remote
c) Copy remote
s) Set configuration password
q) Quit config
n/r/c/s/q> n
name> GDRIVE
Type of storage to configure.
Choose a number from below, or type in your own value
 1 / Amazon Drive
   \ "amazon cloud drive"
 2 / Amazon S3 (also Dreamhost, Ceph, Minio)
   \ "s3"
 3 / Backblaze B2
   \ "b2"
 4 / Dropbox
   \ "dropbox"
 5 / Encrypt/Decrypt a remote
   \ "crypt"
 6 / Google Cloud Storage (this is not Google Drive)
   \ "google cloud storage"
 7 / Google Drive
   \ "drive"
 8 / Hubic
   \ "hubic"
 9 / Local Disk
   \ "local"
10 / Microsoft OneDrive
   \ "onedrive"
11 / Openstack Swift (Rackspace Cloud Files, Memset Memstore, OVH)
   \ "swift"
12 / SSH/SFTP Connection
   \ "sftp"
13 / Yandex Disk
   \ "yandex"
Storage> 7
Google Application Client Id - leave blank normally.
client_id> 
Google Application Client Secret - leave blank normally.
client_secret> 
Remote config
Use auto config?
 * Say Y if not sure
 * Say N if you are working on a remote or headless machine or Y didn't work
y) Yes
n) No
y/n> n
If your browser doesn't open automatically go to the following link: https://accounts.google.com/o/oauth2/auth?client_id=....apps.googleusercontent.com&redirect_uri=u..&response_type=code&scope=https%3A%2F%2Fwww.googleapis.com%2Fauth%2Fdrive&state=3..
Log in and authorize rclone for access
Enter verification code> ~~~~~~웹브라우저상에 뜨는 코드~~~~~~~
--------------------
[GDRIVE]
client_id = 
client_secret = 
token = {"access_token":"...","token_type":"Bearer","refresh_token":"1/u...","expiry":"2018-11-22T16:44:48.736213405+09:00"}
--------------------
y) Yes this is OK
e) Edit this remote
d) Delete this remote
y/e/d> y
Current remotes:

Name                 Type
====                 ====
GDRIVE               drive

e) Edit existing remote
n) New remote
d) Delete remote
r) Rename remote
c) Copy remote
s) Set configuration password
q) Quit config
e/n/d/r/c/s/q> q
```

## Permission

```bash
(py2) osboxes@ubuntu:~$ sudo mkdir /mnt/GDRIVE
(py2) osboxes@ubuntu:~$ sudo chown osboxes /mnt/GDRIVE
(py2) osboxes@ubuntu:~$ ln -s /mnt/GDRIVE ~/GDRIVE
```

## Config Fuse

```bash
(py2) osboxes@ubuntu:~$ sudo nano /etc/fuse.conf
```

------> Add `user_allow_other`


## Using

* 구글드라이브 리스팅
```bash
rclone lsd GDRIVE:/
```

* 싱크 명령
```bash
rclone sync GDRIVE:/ /mnt/GDRIVE
```

* 마운트 명령 (읽기 전용)
```bash
rclone mount --umask 0 --allow-other --read-only GDRIVE:/ /mnt/GDRIVE &
```

* 언마운트 명령
```bash
fusermount -uz /mnt/GDRIVE
```
