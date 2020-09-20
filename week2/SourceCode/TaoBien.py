mod = 1000000007


def calculate_answer_matrix(k):
    if (k == 1):
        return [[2, 1], [1, 1]]
    base_matrix = [[2, 1], [1, 1]]
    matrix = calculate_answer_matrix(int(k / 2))
    trans_matrix = matrix.copy()
    trans_matrix[1][0], trans_matrix[0][1] = trans_matrix[0][1], trans_matrix[1][0]
    result = [[2, 1], [1, 1]]
    for i in range(2):
        for j in range(2):
            result[i][j] = (matrix[i][0] * trans_matrix[j][0] +
                            matrix[i][1] * trans_matrix[j][1]) % mod
    matrix = [[result[0][0], result[0][1]], [result[1][0], result[1][1]]]
    if (k % 2):
        for i in range(2):
            for j in range(2):
                result[i][j] = (matrix[i][0] * base_matrix[j][0] +
                            matrix[i][1] * base_matrix[j][1]) % mod
    return result


n, k = [int(i) for i in input().split()]
print((sum(calculate_answer_matrix(k)[1]) * n) % mod)
