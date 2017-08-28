# Data

## Classification

## Small datasets

### Wisconsin Breast Cancer Dataset
Filename: `cancer.dt`
In, out, train, test: 9, 2, 466, 233
Modifications: Divided each col by 10, replaced ? with 0, ID col removed, shuffled
Source: UCI Machine Learning Repository

### Pima Indians diabetes
Filename: `diabetes.dt`
In, out, train, test: 8, 2, 512, 256
Modifications: Normalized each col, shuffled
Source: UCI Machine Learning Repository

### Glass identification
Filename: `glass.dt`
In, out, train, test: 9, 7, 143, 71
Modifications: Removed ID column, removed class 4, normalized each col, shuffled
Source: UCI Machine Learning Repository

## Large datasets

### Adult census
Filename: `adult.dt`
In, out, train, test: 14, 2, 30148, 15074
Modifications: Unknown values removed, converted to floats, normalized, shuffled
Source: UCI Machine Learning Repository

### MNIST
Filename: `mnist.dt`
In, out, train, test: 784, 10, 60000, 10000
Modifications: All divided by 256.0, original order
Source: http://yann.lecun.com/exdb/mnist/UCI

### Poker hand recognition
Filename: `poker.dt`
In, out, train, test: 10, 10, 683340, 341670
Modifications: Normalized by column, shuffled, original test and train shuffled together
Source: UCI Machine Learning Repository

## Regression

### Abalone
Filename: `abalone.dt`
In, out, instances: 8, 1, 4177
Modifications: Need to clean
Source: UCI Machine Learning Repository

### Forest fires
Filename: `fires.dt`
In, out, instances: 13, 1, 517
Modifications: Need to clean
Source: UCI Machine Learning Repository

### Wine quality
Filename: `quality.dt`
In, out, instances: 12, 1, 4898
Modifications: Need to clean
Source: UCI Machine Learning Repository
