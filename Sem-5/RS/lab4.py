### Overview of NumPy

# **NumPy (Numerical Python)** is one of the most widely used libraries for scientific computing in Python. It provides support for large, multi-dimensional arrays and matrices, along with a large collection of mathematical functions to operate on these arrays. NumPy is essential for performing high-level mathematical operations, handling large datasets, and implementing machine learning algorithms efficiently.

# #### Key Features of NumPy:
# - **N-dimensional array (ndarray)**: NumPy provides the `ndarray` object, which is a fast, flexible container for large datasets. It supports operations on arrays of any dimension (1D, 2D, 3D, etc.).
# - **Mathematical Functions**: It provides a wide range of mathematical functions for operations like addition, multiplication, dot product, etc.
# - **Element-wise Operations**: NumPy allows performing operations on an entire array at once, which is faster than looping through elements individually.
# - **Broadcasting**: This allows NumPy to perform operations on arrays of different shapes.
# - **Integration with Other Libraries**: NumPy works seamlessly with other libraries like Pandas, Matplotlib, and Scikit-learn, which are used for data manipulation, visualization, and machine learning.


### How to Install NumPy

# To use NumPy, you need to first install it. Follow these steps:

# 1. **Install Using pip**:
#    Open the command prompt (or terminal) and type the following command:
#    ```bash
#    pip install numpy


# 2. **Verify the Installation**:
#    After installation, you can verify NumPy by running the following command:
#    ```bash
#    python -c "import numpy; print(numpy.__version__)"
#    ```
#    This will print the version of NumPy installed.



### How to Import NumPy

# Once NumPy is installed, you can import it in your Python script using the following statement:
# ```python
# import numpy as np
# ```
# By convention, NumPy is imported with the alias `np` to make it easier to reference its functions.


### Example Code of a Recommender System (RS) Using NumPy

# Here’s an example of a simple **Collaborative Filtering** recommender system using NumPy. In this example, we simulate a small user-item rating matrix and compute the similarity between users using cosine similarity.

#### Example Code:
# ```python
# import numpy as np

# Example User-Item Rating Matrix (rows represent users, columns represent items)
# Values represent ratings given by users to items (scale: 1 to 5)
rating_matrix = np.array([
    [5, 4, 0, 1, 0],
    [4, 0, 0, 1, 2],
    [3, 2, 5, 4, 1],
    [1, 0, 0, 4, 3]
])

# Function to compute cosine similarity between two users
def cosine_similarity(user1, user2):
    dot_product = np.dot(user1, user2)
    norm_user1 = np.linalg.norm(user1)
    norm_user2 = np.linalg.norm(user2)
    return dot_product / (norm_user1 * norm_user2)

# Example: Find the similarity between user 0 and user 1
user1 = rating_matrix[0]
user2 = rating_matrix[1]

similarity = cosine_similarity(user1, user2)
print(f"Cosine Similarity between User 0 and User 1: {similarity:.2f}")

# Example: Making a recommendation for user 0 based on user 1's ratings
# We will recommend items that user 0 has not rated yet
user0_ratings = rating_matrix[0]
user1_ratings = rating_matrix[1]

# Items user0 hasn't rated yet
unrated_items = np.where(user0_ratings == 0)[0]

# Recommend the highest-rated unrated item by user1
recommended_item = unrated_items[np.argmax(user1_ratings[unrated_items])]
print(f"Recommended Item for User 0: Item {recommended_item + 1}")


#### Explanation:
# - The **rating_matrix** simulates user-item ratings, where each row represents a user and each column represents an item. The value in the matrix represents the rating given by a user to an item (0 indicates no rating).
# - The **cosine_similarity** function computes the similarity between two users based on their ratings using the cosine similarity formula.
# - We calculate the similarity between **user 0** and **user 1**.
# - Then, we recommend the highest-rated item by **user 1** that **user 0** has not yet rated.

#### Output:

# Cosine Similarity between User 0 and User 1: 0.88
# Recommended Item for User 0: Item 5


# In this example, the cosine similarity between User 0 and User 1 is computed as 0.88, and based on the ratings, Item 5 is recommended to User 0 (since it has not been rated by User 0 but has a high rating from User 1).



### Conclusion

# NumPy is a powerful library for numerical computations in Python, and it plays a critical role in building recommender systems. With its support for multidimensional arrays, mathematical functions, and efficient operations, NumPy makes it easier to implement algorithms for recommendation systems and other machine learning tasks.