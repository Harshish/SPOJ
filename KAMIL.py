for i in range(0,10): 
    word = input()
    print(2**sum(word.count(i) for i in 'DFLT'))