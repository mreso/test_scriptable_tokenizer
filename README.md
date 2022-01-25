
The purpose of this repo is to test scriptable tokenizers for pytorch

Prepare environment:

    git clone https://github.com/mreso/test_scriptable_tokenizer.git
    cd test_scriptable_tokenizer/
    sudo apt install python 3.8
    python3.8 -m venv venv
    source venv/bin/activate
    pip install wheel
    pip install Cython
    pip install --pre -r requirements.txt -f https://download.pytorch.org/whl/nightly/cpu/torch_nightly.html

    wget https://download.pytorch.org/libtorch/nightly/cpu/libtorch-shared-with-deps-latest.zip
    unzip libtorch-shared-with-deps-latest.zip

Build:

    python test_tokenizers.py

    mkdir build && cd build
    cmake ..
    make -j

    ./torchtext_kernels ../tokenizer.pt





