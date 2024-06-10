import seaborn as sns
iris = sns.load_dataset('iris')

X = iris['petal_length']
y = iris['petal_width']

import matplotlib.pyplot as plt
plt.scatter(X, y)
plt.xlabel("petal length")
plt.ylabel("petal width")

from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size = 0.4, random_state = 23)

import numpy as np
X_train = np.array(X_train).reshape(-1, 1)

X_test = np.array(X_test).reshape(-1, 1)

from sklearn.linear_model import LinearRegression

lr = LinearRegression()

lr.fit(X_train, y_train)

c = lr.intercept_

m = lr.coef_

Y_pred_train = m*X_train + c
Y_pred_train.flatten()

y_pred_train1 = lr.predict(X_train)

import matplotlib.pyplot as plt
plt.scatter(X_train, y_train)
plt.plot(X_train, y_pred_train1, color ='red')
plt.xlabel("petal length")
plt.ylabel("petal width")

y_pred_test1 = lr.predict(X_test)

import matplotlib.pyplot as plt
plt.scatter(X_test, y_test)
plt.plot(X_test, y_pred_test1, color ='red')
plt.xlabel("petal length")
plt.ylabel("petal width")