# Dockerfiles
* While a build command is being executed, each command is executed one by one, this may lead to a new temporary image being formed for every instruction.
* each instruction is run independently, with build cache being used to speed up the process sometimes.
```
$ docker build -t svendowideit/ambassador .
Sending build context to Docker daemon 15.36 kB
Step 1/4 : FROM alpine:3.2
 ---> 31f630c65071
Step 2/4 : MAINTAINER SvenDowideit@home.org.au
 ---> Using cache
 ---> 2a1c91448f5f
Step 3/4 : RUN apk update &&      apk add socat &&        rm -r /var/cache/
 ---> Using cache
 ---> 21ed6e7fbb73
Step 4/4 : CMD env | grep _TCP= | (sed 's/.*_PORT_\([0-9]*\)_TCP=tcp:\/\/\(.*\):\(.*\)/socat -t 100000000 TCP4-LISTEN:\1,fork,reuseaddr TCP4:\2:\3 \&/' && echo wait) | sh
 ---> Using cache
 ---> 7ea8aef582cc
Successfully built 7ea8aef582cc
```
# Writing a Dockerfile
You can include environment variables
### FROM
It is the basic reference image from which you build your image.
 As such, a valid Docker file must start with a FROM instruction. 
 The image can be any valid image – it is especially easy to start by pulling an image from the Public Repositories.
###ARG
 Can pass variable arguments to the FROM (such that tags or versions).
###RUN 
 It will run the following command on the command line and commit the result to the image.
###CMD
 There can only be one CMD instruction in a Dockerfile. If you list more than one CMD then only the last CMD will take effect.
The main purpose of a CMD is to provide defaults for an executing container.When used in the shell or exec formats, 
the CMD instruction sets the command to be executed when running the image.
```
CMD command param1 param2 (shell form)
```
you may also run into problems with the shell form if you're building a minimal image which doesn't even include a shell binary.
 When Docker is constructing the command to be run it doesn't 
check to see if the shell is available inside the container -- if you don't have /bin/sh in your image, the container will simply fail to start.
```
CMD ["executable","param1","param2"] (exec form, this is the preferred form)
```
```
$ docker run alpine
FATA[0000] Error response from daemon: No command specified
```

 CMD can be overridden by giving some command to execute during runtime of image.
If you use the shell form of the CMD, then the <command> will execute in /bin/sh -c:

######Using ENTRYPOINT with CMD
 When both an ENTRYPOINT and CMD are specified, the CMD string(s) will be appended to the ENTRYPOINT in order to generate the container's command string.
```
FROM ubuntu:trusty
ENTRYPOINT ["/bin/ping","-c","3"]
CMD ["localhost"]
```
Docker run will give the following reply:
``` 
$ docker build -t ping .
[truncated]

$ docker run ping
PING localhost (127.0.0.1) 56(84) bytes of data.
64 bytes from localhost (127.0.0.1): icmp_seq=1 ttl=64 time=0.025 ms
64 bytes from localhost (127.0.0.1): icmp_seq=2 ttl=64 time=0.038 ms
64 bytes from localhost (127.0.0.1): icmp_seq=3 ttl=64 time=0.051 ms

--- localhost ping statistics ---
3 packets transmitted, 3 received, 0% packet loss, time 1999ms
rtt min/avg/max/mdev = 0.025/0.038/0.051/0.010 ms

$ docker ps -l
CONTAINER ID IMAGE COMMAND CREATED
82df66a2a9f1 ping:latest "/bin/ping -c 3 localhost" 6 seconds ago
```


###ADD
This is used to add the files from <src> to <dest>. Source must be on the host and destination is where the files/folder has to be copied inside the container. The good thing about ADD is that it can import files from URLs also and store in the container.
ADD can also be used to add a tar file to the container at some particular directory and it will automatically untar it.
###COPY
While add can be too much to handle sometimes, a much simpler version is COPY. It stands by its name and just copies files from the source to destination.
It is suggested to simply use COPY instead of ADD  unless really necessary.
###EXPOSE
The EXPOSE instruction does not actually publish the port. It functions as a type of documentation between the person who builds the image and the person who runs the container, 
about which ports are intended to be published