import torch
from torchtext import transforms

sentence = "The green grasshopper jumped over the fence"

t = torch.jit.load('tokenizer.pt')

print(t(sentence))