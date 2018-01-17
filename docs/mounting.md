# Mounting data to the container

You can mount data on a container from the host or another container.
The benefit of this is that this mount will remain even after the container is deleted. 
The changes made to the mount on the container are reflected in the host location as well. 

 Data can be mounted to the containers using -v <src>:<destination>.
 If the <src> directory is not existent on the host, this command will create a new directory on the host, which will be managed by the docker daemon.

 ```
 docker run -it -v <src>:<dest> -d img_name 
```

