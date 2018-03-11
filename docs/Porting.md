# Porting an application across platforms.
 We first pull a mysql image and run a mysql container.
 
 ```
 docker run -it -e MYSQL_ROOT_PASSWORD=hello -d mysql:latest
 ```
 
 We'll now insert data into the databse.
 
 ![Screenshot](https://github.com/purbid/docker_workshop/blob/master/docs/sqltable_insert_values.png)
 
 We now commit the changes to a new image.
  ```
  docker commit <cont_id> 
  ```
 We now run a new container out of this image, and we should see the tables in this new container(supposedly).....
 
 
 
 
 
