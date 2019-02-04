FROM gitpod/workspace-full-vnc:latest

RUN git clone https://github.com/op07n/qt3.git

RUN cd qt3

RUN ./configure -thread

RUN make

# install dependencies
RUN apt-get update

RUN apt-get install -y  matchbox twm

RUN apt-get clean && rm -rf /var/cache/apt/* && rm -rf /var/lib/apt/lists/* && rm -rf /tmp/*

