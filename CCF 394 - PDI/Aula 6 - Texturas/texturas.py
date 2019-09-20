#https://gogul09.github.io/software/texture-recognition
#https://scikit-learn.org/stable/auto_examples/svm/plot_iris.html
import cv2
import numpy as np
import os
import glob
import mahotas as mt
from sklearn.svm import LinearSVC
from sklearn import svm
import csv

# function to extract haralick textures from an image
def extract_features(image):
        # calculate haralick texture features for 4 types of adjacency
        textures = mt.features.haralick(image)
        # take the mean of it and return it
        ht_mean  = textures.mean(axis=0)
        print("ht_mean ",ht_mean)
        
        return ht_mean

# load the training dataset
train_path  = "dataset/train"
train_names = os.listdir(train_path)
print(train_names)

# empty list to hold feature vectors and train labels
train_features = []
train_labels   = []

# loop over the training dataset
print ("[STATUS] Started extracting haralick textures..")
for train_name in train_names:
        cur_path = train_path + "/" + train_name
        cur_label = train_name
        i = 1
        print(cur_path)
       
        for file in glob.glob(cur_path ):
                print( "Processing Image - {} in {}".format(i, cur_label))
                # read the training image
                image = cv2.imread(file)

                # convert the image to grayscale
                gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

                # extract haralick texture from the image
                features = extract_features(gray)

                # append the feature vector and label
                train_features.append(features)
                train_labels.append(cur_label)
                # show loop update
                i += 1
                
               
with open('teste.csv', mode='w') as teste:
                  teste_w = csv.writer(teste, delimiter=',', quotechar='"', quoting=csv.QUOTE_MINIMAL)
                  for linha in train_features:
                          teste_w.writerow(linha)

# have a look at the size of our feature vector and labels
print ("Training features: {}".format(np.array(train_features).shape))
print ("Training labels: {}".format(np.array(train_labels).shape))

# create the classifier
print ("[STATUS] Creating the classifier..")
clf_svm = LinearSVC(C=1.0,random_state=11)
#clf_svm=svm.SVC(kernel='rbf', gamma=0.7, C=1.0)
#clf_svm= svm.SVC(kernel='poly', degree=2, C=1.0)
# fit the training data and labels
print ("[STATUS] Fitting data/label to model..")
clf_svm.fit(train_features, train_labels)

# loop over the test images
test_path = ("dataset/test")
for file in glob.glob(test_path + "/*.jpg"):
        # read the input image
        image = cv2.imread(file)

        # convert to grayscale
        gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

        # extract haralick texture from the image
        features = extract_features(gray)

        # evaluate the model and predict label
        prediction = clf_svm.predict(features.reshape(1, -1))[0]

        # show the label
        cv2.putText(image, prediction, (20,30), cv2.FONT_HERSHEY_SIMPLEX, 1.0, (0,255,255), 3)
        print ("Prediction - {}".format(prediction))

        # display the output image
        cv2.imshow("Test_Image", image)
        cv2.waitKey(0)
