# Installing docker




Docker can be downloaded from the steps given on docker docs.
Just type docker for centos in Google and open the first link and follow the steps.
After installation, you need to specify the proxies(if required) for docker 
explicitly in another file called /etc/systemd/system/docker.service.d/http-proxy.conf. file 

#* It is necessary to have a kernel version of above 3.10 and if using CentOS a version of 7 and above.


Steps to download can be found at 
```
https://docs.docker.com/engine/installation/linux/docker-ce/ubuntu/#install-using-the-repository
```
To summarize, the download consists of the following commands:
```
$ sudo apt-get update

$ sudo apt-get install \
    apt-transport-https \
    ca-certificates \
    curl \
    software-properties-common
	
$ curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -

$ sudo apt-key fingerprint 0EBFCD88

$ sudo add-apt-repository \
   "deb [arch=amd64] https://download.docker.com/linux/ubuntu \
   $(lsb_release -cs) \
   stable"
   
$ sudo apt-get update

$ sudo apt-get install docker-ce

$ apt-cache madison docker-ce
```