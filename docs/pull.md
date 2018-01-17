# Pulling images from the docker hub

* Docker images are objects which form the basis for the containers. To say in layman's terms(although a naive description a docker image is a template for a particular function.
  Like using the ubuntu image you start up a ubuntu container, using a mysqldb image, you can start a mysql database container, and so on.
* Images a resulted from executing a dockerfile(Discussed later onn).
* One image can be used to start multiple independent containers, that is the beauty of images.

To pull the images from docker hub the command used is docker pull. the following command when executed from bash will pull an ubuntu image from docker hub.

```
docker pull ubuntu
```
To list all the exsisting images:
```
docker images
```
An image is identified by its Image ID. The meta data about your images resides in /var/lib/docker/graph/<id> in json format.

When you execute docker pull, image is pulled from Docker Hub. But when an image has already been pulled, and you give docker pull again, it is pulled from local repository, thus saving time.
![Screenshot](pull.png)




