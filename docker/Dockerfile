FROM ubuntu:18.04


RUN apt-get update && apt-get install -y python3 \
  python3-pip \
  libxrender-dev libsm6 libxext6 
  #virtualenv \
  #libssl-dev \
  #libpq-dev \
  #build-essential \
  #libfontconfig1 \
  #libfontconfig1-dev
RUN pip3 install setuptools pip --upgrade --force-reinstall

# COPY ./requirements.txt /requirements.txt
RUN pip3 install --upgrade pip
# RUN pip3 install -r requirements.txt

WORKDIR /code
COPY ./code /code

# CMD ["uwsgi", "--ini", "/app/uwsgi.ini"]


# gcc code.c -fopenmp -o run.out
# ./run.out

# base64 /dev/urandom | head -c 20000000 > file1.txt
