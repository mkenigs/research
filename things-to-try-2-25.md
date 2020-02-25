
If we want to run a deep learning model, how can it run inside the unikernel
i.e. imagenet, resnet, inception, mobilenet

Is it overkill to run this whole image learning algorithm in the unikernel?
Does it reduce the delta between unik and docker?

Does the docker image size include the base image or just the COW filesystem on
top?


Pharonix for cloud benchmarking
Try one of the benchmarks from the pharonix/cloud suite first before the large
neural nets:
