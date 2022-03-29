
The purpose of this repo is to test scriptable tokenizers for pytorch

This example uses a new PR (https://github.com/pytorch/text/pull/1660) which removed the libpython dependencies libtorchtext.so 

Prepare environment:

    sudo apt install python 3.8
    python3.8 -m venv venv
    source venv/bin/activate
    pip install wheel
    pip install Cython

    pip3 install torch torchtext --extra-index-url https://download.pytorch.org/whl/cpu

Compile libtorchtext.so

    git clone https://github.com/Nayef211/text.git
    cd text
    git checkout feature/cmake_build
    git submodule update --init --recursive
    pip install ninja
    mkdir torchtext/lib
    python setup.py develop

    cd build
    rm -rf *
    cmake \
        -DCMAKE_PREFIX_PATH=`python -c 'import torch;print(torch.utils.cmake_prefix_path)'` \
        -DRE2_BUILD_TESTING:BOOL=OFF \
        -DBUILD_TESTING:BOOL=OFF \
        -DSPM_ENABLE_SHARED=OFF  \
        ..
    cmake --build . --config Release


Compile example

    git clone https://github.com/mreso/test_scriptable_tokenizer.git
    cd test_scriptable_tokenizer/

    wget https://download.pytorch.org/libtorch/nightly/cpu/libtorch-shared-with-deps-latest.zip
    unzip libtorch-shared-with-deps-latest.zip

    mkdir build && cd build
        
    make -j

Run example

    python test_tokenizers.py

    ./torchtext_kernels ../tokenizer.pt





