// #include <torch/torch.h>
// #include <torch/script.h>

// int main(void) {
//     auto tokenizer = torch::jit::load("../tokenizer.pt");

// }

#include <torch/script.h>
#include <torch/nn/functional/activation.h>

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, const char* argv[]) {

    std::cout << "Loading model...\n";

    torch::jit::script::Module module;
    try {
        module = torch::jit::load(argv[1]);
    } catch (const c10::Error& e) {
        return -1;
    }

    torch::NoGradGuard no_grad; // ensures that autograd is off

    namespace F = torch::nn::functional;
    
    torch::jit::IValue tokens_ivalue = module.forward(std::vector<c10::IValue>(1,"test@gmail.com 00000001"));
    std::cout << "result " << tokens_ivalue << '\n';

    return 0;
}