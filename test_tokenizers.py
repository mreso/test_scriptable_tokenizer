from torchtext import transforms
import torch

sentence = "The green grasshopper jumped over the fence"

encoder_json = "gpt2_bpe_encoder.json"
bpe_vocab = "gpt2_bpe_vocab.bpe"
tokenizer = transforms.GPT2BPETokenizer(
    encoder_json_path=encoder_json,
    vocab_bpe_path=bpe_vocab)

tokenizer = torch.jit.script(tokenizer)

torch.jit.save(tokenizer, 'tokenizer.pt')

print(tokenizer(sentence))

t = torch.jit.load('tokenizer.pt')

print(t(sentence))