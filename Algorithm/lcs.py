"""lcs doc string."""
# 2010-12343 박상문
'''
 in b, we have 3 choice.
 1 ->  left
 2 ->  up
 3 ->  digonal
'''
# LCS 위한 2개의 함수 정의


def lcs_length(str1, str2):
    """Retrun LCS's length."""
    len1 = len(str1)  # m
    len2 = len(str2)  # n

    b = [[0 for col in range(len2 + 1)] for row in range(len1 + 1)]
    c = [[0 for col in range(len2 + 1)] for row in range(len1 + 1)]

    for i in range(1, len1 + 1):
        for j in range(1, len2 + 1):
            if (str1[i - 1] == str2[j - 1]):
                c[i][j] = c[i - 1][j - 1] + 1
                b[i][j] = 3
            elif (c[i - 1][j] >= c[i][j - 1]):
                c[i][j] = c[i - 1][j]
                b[i][j] = 2
            else:
                c[i][j] = c[i][j - 1]
                b[i][j] = 1
    return c, b


def print_lcs(b, strr, i, j):
    """For print LCS."""
    s = ''
    if i == 0 or j == 0:
        return ''
    if b[i][j] == 3:
        s += print_lcs(b, strr, i - 1, j - 1)
        s += strr[i - 1]
        return s
    elif b[i][j] == 2:
        s += print_lcs(b, strr, i - 1, j)
        return s
    else:
        s += print_lcs(b, strr, i, j - 1)
        return s

# 실제 gene에 적용하기 위해 input 처리하는 함수와
# 반복 실행하는 함수 만듬


# geneA = open("geneA.fasta")
# geneB = open("geneB.fasta")

# for line in geneA:
#    print(line)

# geneA.close()
# geneB.close()

X = "ABCBDAB"
Y = "BDCABA"

x, y = lcs_length(X, Y)
for line in x:
    print(line)
print('')
for line in y:
    print(line)
print(print_lcs(y, X, 7, 6))
