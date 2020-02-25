#!/bin/bash

sudo systemctl start docker
sudo modprobe loop

unik daemon --debug

# IN ANOTHER TERMINAL
unik target --host localhost
unik rmi --force --image myImage # Clean up from any previous attempts
unik build --name myImage --path ./ --base includeos --language cpp --provider virtualbox
unik run --instanceName myInstance --imageName myImage

# See the image size itself
ll ~/.unik/virtualbox/images/myImage/boot.vmdk

# For comparison
sudo docker run -p 80:80 -it --rm strm/helloworld-http

