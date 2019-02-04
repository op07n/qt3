FROM gitpod/workspace-full-vnc:latest

USER root

RUN git clone https://github.com/op07n/qt3.git

USER gitpod

RUN cd /workspace/qt3

RUN echo "yes" | ./configure -thread -fast

RUN make

