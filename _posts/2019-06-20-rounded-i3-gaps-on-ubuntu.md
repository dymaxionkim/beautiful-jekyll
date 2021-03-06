---
layout: post
published: true
title: Rounded i3-gaps on Ubuntu
subtitle: 창의 모서리를 둥글게 개량한 i3-gaps 윈도우 매니저 설치
date: '2019-06-20'
bigimg: /img/bigimg48.jpg
image: 'https://raw.githubusercontent.com/i3/i3/next/docs/logo-30.png'
tags: software
---
## i3 wm

[i3 윈도우 매니저](https://i3wm.org/)는 C언어로 개발되었고, 비슷한 종류의 다른 타일링 윈도우 매니저들보다 비교적 최근에 나왔다는 특성이 있다.  때문에 부가적인 기능들이 대체로 잘 갖추어져 있고, 빠른 응답속도와 가벼운 크기를 잘 유지한다.

## i3-gaps

최근에는 i3에서 포크하여, 윈도우간에 갭을 줄 수 있는 옵션을 추가한 [i3-gaps](https://github.com/Airblader/i3)가 오리지널보다 더 많이 사용되는 것 같다.

## Rounded i3-gaps

여기서 한발 더 나아가, 윈도우 코너 부분에 라운드를 줘서 좀 더 예쁘게 수정한 [Rounded i3-gaps](https://github.com/resloved/i3)도 있다.

여기서는 i3-gaps 또는 Rounded i3-gaps 어느쪽이든 소스코드를 clone 받은후, 컴파일해서 설치하고, 기본적인 설정을 부여해 주는 절차를 기술한다.  기본 OS는 Ubuntu 계열이면 다 된다.

## 전제조건

* Ubuntu 계열일 것.
* 디스플레이 매니저가 설치되어 있을 것. (gdm3, lightdm...)
* git이 설치되어 있을 것.
* 다음 유틸리티들도 설치되어 있으면 좋다 (설정파일과 그대로 매칭되는 권장사항) : qlipper, nm-applet, lxpolkit, pasystray, blueman-manager, feh, compton, terminator, min, firefox-trunk, pcmanfm, rofi ...


## 빌드 및 설치 스크립트

`3-gaps.sh` 파일을 하나 만들고, 아래와 같은 내용을 써 준 다음 실행권한 부여하고 실행해 주면 된다.

```
#!/bin/bash
sudo apt install -y libxcb1-dev libxcb-keysyms1-dev libpango1.0-dev libxcb-util0-dev libxcb-icccm4-dev libyajl-dev libstartup-notification0-dev libxcb-randr0-dev libev-dev libxcb-cursor-dev libxcb-xinerama0-dev libxcb-xkb-dev libxkbcommon-dev libxkbcommon-x11-dev autoconf libxcb-xrm0 libxcb-xrm-dev automake

mkdir $HOME/git
cd $HOME/git
 
# clone the repository
#git clone https://www.github.com/Airblader/i3 i3-gaps # Gaps
git clone https://github.com/resloved/i3.git i3-gaps # Gaps+Rounded
cd i3-gaps
 
# compile & install
autoreconf --force --install
rm -rf build/
mkdir -p build && cd build/
 
# Disabling sanitizers is important for release versions!
# The prefix and sysconfdir are, obviously, dependent on the distribution.
../configure --prefix=/usr --sysconfdir=/etc --disable-sanitizers
make
sudo make install
```

* i3status 설치 : i3bar에 상태표시해 주는 앱을 추가해 준다.


```bash
sudo apt install i3status
```

## 설정파일

* `~/.config/i3/config` 파일을 만들고 아래와 같은 내용을 넣는다. (단축키 등 기본적인 설정은 거의 변경하지 않았고, 약간만 수정한 것임)

```
# This file has been auto-generated by i3-config-wizard(1).
# It will not be overwritten, so edit it as you like.
#
# Should you change your keyboard layout some time, delete
# this file and re-run i3-config-wizard(1).
#
 
# i3 config file (v4)
#
# Please see https://i3wm.org/docs/userguide.html for a complete reference!
 
set $mod Mod4
 
# Font for window titles. Will also be used by the bar unless a different font
# is used in the bar {} block below.
#font pango:monospace 8
font pango:D2Coding 11
 
# This font is widely installed, provides lots of unicode glyphs, right-to-left
# text rendering and scalability on retina/hidpi displays (thanks to pango).
#font pango:DejaVu Sans Mono 8
 
# Before i3 v4.8, we used to recommend this one as the default:
# font -misc-fixed-medium-r-normal--13-120-75-75-C-70-iso10646-1
# The font above is very space-efficient, that is, it looks good, sharp and
# clear in small sizes. However, its unicode glyph coverage is limited, the old
# X core fonts rendering does not support right-to-left and this being a bitmap
# font, it doesn’t scale on retina/hidpi displays.
 
# Use Mouse+$mod to drag floating windows to their wanted position
floating_modifier $mod
 
# start a terminal
#bindsym $mod+Return exec i3-sensible-terminal
bindsym $mod+Return exec terminator
 
# kill focused window
bindsym $mod+Shift+q kill
 
# start dmenu (a program launcher)
#bindsym $mod+d exec dmenu_run
bindsym $mod+d exec rofi -show drun
# There also is the (new) i3-dmenu-desktop which only displays applications
# shipping a .desktop file. It is a wrapper around dmenu, so you need that
# installed.
# bindsym $mod+d exec --no-startup-id i3-dmenu-desktop
 
# Some applications
bindsym $mod+Ctrl+m exec min
bindsym $mod+Ctrl+w exec firefox-trunk
bindsym $mod+Ctrl+f exec pcmanfm
 
# Screenshot
bindsym --release Print exec scrot
bindsym --release $mod+Print exec scrot -s
 
# change focus
bindsym $mod+j focus left
bindsym $mod+k focus down
bindsym $mod+l focus up
bindsym $mod+semicolon focus right
 
# alternatively, you can use the cursor keys:
bindsym $mod+Left focus left
bindsym $mod+Down focus down
bindsym $mod+Up focus up
bindsym $mod+Right focus right
 
# move focused window
bindsym $mod+Shift+j move left
bindsym $mod+Shift+k move down
bindsym $mod+Shift+l move up
bindsym $mod+Shift+semicolon move right
 
# alternatively, you can use the cursor keys:
bindsym $mod+Shift+Left move left
bindsym $mod+Shift+Down move down
bindsym $mod+Shift+Up move up
bindsym $mod+Shift+Right move right
 
# split in horizontal orientation
bindsym $mod+h split h
 
# split in vertical orientation
bindsym $mod+v split v
 
# enter fullscreen mode for the focused container
bindsym $mod+f fullscreen toggle
 
# change container layout (stacked, tabbed, toggle split)
bindsym $mod+s layout stacking
bindsym $mod+w layout tabbed
bindsym $mod+e layout toggle split
 
# toggle tiling / floating
bindsym $mod+Shift+space floating toggle
 
# change focus between tiling / floating windows
bindsym $mod+space focus mode_toggle
 
# focus the parent container
bindsym $mod+a focus parent
 
# focus the child container
#bindsym $mod+d focus child
 
# Define names for default workspaces for which we configure key bindings later on.
# We use variables to avoid repeating the names in multiple places.
set $ws1 "1"
set $ws2 "2"
set $ws3 "3"
set $ws4 "4"
set $ws5 "5"
set $ws6 "6"
set $ws7 "7"
set $ws8 "8"
set $ws9 "9"
set $ws10 "10"
 
# switch to workspace
bindsym $mod+1 workspace $ws1
bindsym $mod+2 workspace $ws2
bindsym $mod+3 workspace $ws3
bindsym $mod+4 workspace $ws4
bindsym $mod+5 workspace $ws5
bindsym $mod+6 workspace $ws6
bindsym $mod+7 workspace $ws7
bindsym $mod+8 workspace $ws8
bindsym $mod+9 workspace $ws9
bindsym $mod+0 workspace $ws10
 
# move focused container to workspace
bindsym $mod+Shift+1 move container to workspace $ws1
bindsym $mod+Shift+2 move container to workspace $ws2
bindsym $mod+Shift+3 move container to workspace $ws3
bindsym $mod+Shift+4 move container to workspace $ws4
bindsym $mod+Shift+5 move container to workspace $ws5
bindsym $mod+Shift+6 move container to workspace $ws6
bindsym $mod+Shift+7 move container to workspace $ws7
bindsym $mod+Shift+8 move container to workspace $ws8
bindsym $mod+Shift+9 move container to workspace $ws9
bindsym $mod+Shift+0 move container to workspace $ws10
 
# reload the configuration file
bindsym $mod+Shift+c reload
# restart i3 inplace (preserves your layout/session, can be used to upgrade i3)
bindsym $mod+Shift+r restart
# exit i3 (logs you out of your X session)
bindsym $mod+Shift+e exec "i3-nagbar -t warning -m 'You pressed the exit shortcut. Do you really want to exit i3? This will end your X session.' -B 'Yes, exit i3' 'i3-msg exit'"
 
# resize window (you can also use the mouse for that)
mode "resize" {
        # These bindings trigger as soon as you enter the resize mode
 
        # Pressing left will shrink the window’s width.
        # Pressing right will grow the window’s width.
        # Pressing up will shrink the window’s height.
        # Pressing down will grow the window’s height.
        bindsym j resize shrink width 10 px or 10 ppt
        bindsym k resize grow height 10 px or 10 ppt
        bindsym l resize shrink height 10 px or 10 ppt
        bindsym semicolon resize grow width 10 px or 10 ppt
 
        # same bindings, but for the arrow keys
        bindsym Left resize shrink width 10 px or 10 ppt
        bindsym Down resize grow height 10 px or 10 ppt
        bindsym Up resize shrink height 10 px or 10 ppt
        bindsym Right resize grow width 10 px or 10 ppt
 
        # back to normal: Enter or Escape or $mod+r
        bindsym Return mode "default"
        bindsym Escape mode "default"
        bindsym $mod+r mode "default"
}
 
bindsym $mod+r mode "resize"
 
# SET GAPS
#smart_gaps on
for_window [class="^.*"] border pixel 1
gaps inner 10
gaps outer 10
 
 
# Floating programs
for_window [class="Pavucontrol"] floating enable
for_window [class="Pavucontrol"] resize shrink left 100, resize shrink right 100, resize shrink down 50, resize shrink up 50
 
 
##### LAUNCH ######################################
# STARTUP
exec --no-startup-id qlipper &
exec --no-startup-id nm-applet &
exec --no-startup-id lxpolkit &
exec --no-startup-id pasystray &
#exec --no-startup-id blueman-manager &
 
# RELOAD
exec_always --no-startup-id feh --bg-fill /home/osboxes/.Wallpaper/Wallpaper.jpg &
exec_always --no-startup-id compton -cCGfF -o 0.4 -O 200 -I 200 -t 0 -l 0 -r 3 -D2 -m 0.9 &
 
# Start i3bar to display a workspace bar (plus the system information i3status
# finds out, if available)
bar {
        height 20
        position top
        i3bar_command i3bar
        status_command i3status
}
```

* `~/.config/i3status/config` 파일도 만들고 아래 내용을 넣어준다.

```
# i3status configuration file.
# see "man i3status" for documentation.
 
# It is important that this file is edited as UTF-8.
# The following line should contain a sharp s:
# ß
# If the above line is not correctly displayed, fix your editor first!
 
general {
        colors = true
        interval = 5
}
 
#order += "ipv6"
order += "disk /"
#order += "wireless _first_"
#order += "ethernet _first_"
#order += "battery all"
order += "load"
order += "cpu_usage"
order += "tztime local"
 
wireless _first_ {
        format_up = "W: (%quality at %essid) %ip"
        format_down = "W: down"
}
 
ethernet _first_ {
        # if you use %speed, i3status requires root privileges
        format_up = "E: %ip (%speed)"
        format_down = "E: down"
}
 
battery all {
        format = "%status %percentage %remaining"
}
 
tztime local {
        format = "%Y%m%d %a %H:%M:%S"
}
 
load {
        format = "load %1min"
}
 
disk "/" {
        format = "hdd %used/%total"
}
 
cpu_usage {
        format = "cpu %usage"
}
```

## 셋팅 결과

![2019-06-20-164419_1920x1080_scrot](https://user-images.githubusercontent.com/12775748/59842913-793c1600-9392-11e9-8775-ea5a961efa73.png)

![2019-06-20-235807_1366x768_scrot](https://user-images.githubusercontent.com/12775748/59859334-7dc6f580-93b7-11e9-9bbd-fbd08147a2ea.png)

끝!
