# 42 Cursus for tbrizon student
![](Screenshots/42.png)

# roger-skyline-1
This project, roger-skyline-1 let you install a Virtual Machine, discover the basics about system and network administration as well as a lots of services used on a server machine.

## Summary <a id="summary"></a>

- [Summary](#summary)
- [Virtual Machine Setup](#VMsetup)
- [Users](#suduser)
- [Setup IP](#IP)


## Virtual Machine Installation <a id="VMsetup"></a>

For this project, you will need to downlad a virtual image disk, you can find one [here](https://cdimage.debian.org/debian-cd/current/amd64/iso-cd/). You will need to run your machine with virtual box.
The VM need to have 8Gb disk size, so i put 7.46 cause VirtualBox allocate it in GiB and 7.46 GiB ~=  8.01 Gb.
In order to create the static IP, choose to in the setting section of your machine, in *Network* choose *bridged adaptator*
1. Setup the root password, and create a non-root user
2. Create a primary partition mounted on / with 4.2Gb a logical mounted on /homeå with 2.8Gb. Then i create a swap area of 1Gb
3. Only install SSH, nothing else (no desktop environnement for exemple)
4. install GRUB on the master boot record

## Add new suduser <a id=suduser">
You need to install sudo and vim.
```bash
apt-get update -y && apt-get upgrade -y
apt-get install sudo vim -y
```
To allow your user to have sudo privilege (as root), you will need to edit the file `etc/sudoers`
```bash
vim /etc/sudoers
```
The file outpout should be like that:

```console
#
# This file MUST be edited with the 'visudo' command as root.
#
# Please consider adding local content in /etc/sudoers.d/ instead of
# directly modifying this file.
#
# See the man page for details on how to write a sudoers file.
#
Defaults        env_reset
Defaults        mail_badpass
Defaults        secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbi$

# Host alias specification

# User alias specification

# Cmnd alias specification

# User privilege specification
root    ALL=(ALL:ALL) ALL
tbrizon    ALL=(ALL:ALL) NOPASSWD:ALL

# Members of the admin group may gain root privileges

# Allow members of group sudo to execute any command
%sudo   ALL=(ALL:ALL) ALL

# See sudoers(5) for more information on "#include" directives:

#includedir /etc/sudoers.d
```

## Setup IP <a id="IP"></a>

Edit the file `/etc/network/interfaces` and setup our primary network

```bash
cat /etc/network/interfaces
```

Output:

```console
source /etc/network/interfaces.d/*

#The loopback Network interface
auto lo
iface lo inet loopback

#The primary network interface
auto enp0s3
```
