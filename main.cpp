#include <torch/torch.h>
#include <torch/script.h>

int main(void) {
    auto tokenizer = torch::jit::load("../tokenizer.pt");

}