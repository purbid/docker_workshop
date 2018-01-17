# Starting the container.

Containers are instances or images and hence many containers can be made from one image. 
To create and run a container,a run command is given. Ps command shows 
the currently running containers while ps –a shows all the containers.

## To view the container IP:
docker inspect <container_name> | grep IPAddr

## List of containers
The container are stored on the host at /var/lib/docker/container.
 If you list that location, you can get the list of all the container ids.
 
 ![Screenshot](dockerps.png)

##Port addressing
When a container is run, the application usually runs on the default port(80 for apache, for example).
 To run it on a particular port say, 700 we can write –p 700:80 
 
 Some of the other useful container commands are:
 
```
 docker ps 
 ```
 
lists all currently running containers.

 ```
 docker ps -a
 ```
 
 lists all containers
 
 ```
 docker run --name cont_name -it <img_name> bash
 ```
 
 Start a container interactively and make bash the entrypoint.
 
# Example of starting an apache server container
  ![Screenshot](apache_run.png)
 Note that you should an index.html file at public-html already.Otherwise, there is nothing to show and while serving on browse, 404 error is thrown.
 
Output is something like(depending on your dockerfile)
 ![Screenshot](apache.png)