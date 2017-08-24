using MNIST

i=1
train_data = zeros(60000, 794);
for j in randperm(60000)
    train_data[i, 1:784] = MNIST.trainfeatures(j)/256.0
    train_data[i, Int64(785+MNIST.trainlabel(j))] = 1.0
    i+=1
end

i=1
test_data = zeros(10000, 794);
for j in randperm(10000)
    test_data[i, 1:784] = MNIST.testfeatures(j)/256.0
    test_data[i, Int64(785+MNIST.testlabel(j))] = 1.0
    i+=1
end

data = [train_data; test_data]
writedlm("mnist.dt", data, ' ')
