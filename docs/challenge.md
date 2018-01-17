We now have run applications on containers.

Next is moving this application to the docker hub with compromising the docker container data.

#challenge: Ship the mysql container to docker hub and pull it to your system with the database intact.

#HINT: MYSQL uses volumes to mount data on to the container, hence every time you commit the changes to a new image, the changes arent shown.
Try to copy your data volume inside the container to a new location(inside the container only) and can solve the issue.
