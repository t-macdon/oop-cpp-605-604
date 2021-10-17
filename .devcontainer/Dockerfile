# See here for image contents: https://github.com/microsoft/vscode-dev-containers/tree/v0.191.1/containers/cpp/.devcontainer/base.Dockerfile

# [Choice] Debian / Ubuntu version: debian-11, debian-10, debian-9, ubuntu-20.04, ubuntu-18.04
ARG VARIANT="buster"
FROM mcr.microsoft.com/vscode/devcontainers/cpp:0-${VARIANT}

RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install --no-install-recommends \
    default-jdk \
    graphviz \
    doxygen \
    cmake \
    python3-pip \
    neovim \
    ghostscript \
    poppler-utils \
    && rm -rf /var/lib/apt/lists/*

RUN python3 -m pip install --no-cache \
    hpp2plantuml