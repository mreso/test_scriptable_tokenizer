
The purpose of this repo is to test scriptable tokenizers for pytorch

Prepare environment:

    python3.8 -m venv venv

    source venv/bin/activate

    pip install -r requirements.txt -f https://download.pytorch.org/whl/nightly/cu113/torch_nightly.html

Build:

    git clone https://github.com/mreso/test_scriptable_tokenizer.git

    cd test_scriptable_tokenizer.git

    python test_tokenizers.py

    mkdir build && cd build

    cmake -DCMAKE_PREFIX_PATH=../venv/lib64/python3.8/site-packages/torch ..

    make

    ./test_tokenizer


