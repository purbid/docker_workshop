# Building a wordpress application out of containers.
Now that we know about images and containers, lets put it all together and build an application out of this.
We are going to use a Wordpress image and a Mysql image and link them to access our word press blogsite on our localhost/VM IP.
We first install a mysql image using command
```
docker pull mysql
```
Now we run the container from this image
```
docker run --name purbid -e MYSQL_ROOT_PASSWORD=root -d mysql 
```
And then attach to the detached container 
```
docker exec -it <cont_id> bash
```
We now take a wordpress image and ,run a container and link that container to the database.
```
docker run --name wordpress_pb --link <cont_name>:mysql -p 8080:80 -d wordpress
``` 
The wordpress site can now be accessed at http://127.0.0.1:8080 or <host_ip>:8080

In case, an external database is to be used,
```
$ docker run --name some-wordpress -e WORDPRESS_DB_HOST=10.1.2.3:3306 \
    -e WORDPRESS_DB_USER=... -e WORDPRESS_DB_PASSWORD=... -d wordpress
```
 ![Screenshot](wordpress.png)