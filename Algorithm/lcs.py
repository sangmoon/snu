"""lcs doc string."""
# 2010-12343 박상문
from math import floor


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


def print_lcs(b, strr, i, j, flag):
    """For print LCS."""
    # flag : row : 1 coloum : 2
    s = ''
    if flag == 1:
        if i == 0 or j == 0:
            return ''
        if b[i][j] == 3:
            s += print_lcs(b, strr, i - 1, j - 1, flag)
            s += strr[i - 1]
            return s
        elif b[i][j] == 2:
            s += print_lcs(b, strr, i - 1, j, flag)
            s += '_'
            return s
        else:
            s += print_lcs(b, strr, i, j - 1, flag)
            return s
    else:
        if i == 0 or j == 0:
            return ''
        if b[i][j] == 3:
            s += print_lcs(b, strr, i - 1, j - 1, flag)
            s += strr[j - 1]
            return s
        elif b[i][j] == 2:
            s += print_lcs(b, strr, i - 1, j, flag)
            return s
        else:
            s += print_lcs(b, strr, i, j - 1, flag)
            s += '_'
            return s


# 실제 gene에 적용하기 위해 input 처리하는 함수와
# 반복 실행하는 함수 만듬


def find_lcs_of_two(slice_a, slice_b):
    """Compare lcs of two input."""
    x, y = lcs_length(slice_a, slice_b)
    length = x[len(slice_a)][len(slice_b)]

    lcs_a = print_lcs(y, slice_a, len(slice_a), len(slice_b), 1)
    lcs_b = print_lcs(y, slice_b, len(slice_a), len(slice_b), 0)

    lcs_a = '_' * (len(slice_a) - len(lcs_a)) + lcs_a
    lcs_b = '_' * (len(slice_b) - len(lcs_b)) + lcs_b
    return lcs_a, lcs_b, length

# main start
file_A = open("geneA.fasta", 'r')
file_B = open("geneB.fasta", 'r')

name_A = file_A.readline()
name_B = file_B.readline()

lines_A = file_A.readlines()
lines_B = file_B.readlines()

gene_A = ""
gene_B = ""

for line in lines_A:
    gene_A += line.strip()

for line in lines_B:
    gene_B += line.strip()
# 전처리 끝

for i in range(floor(len(gene_A) / 50)):
    interval_A = 0
    if len(gene_A) - 50 * i <= 50:
        break
    elif 51 <= len(gene_A) - 50 * i <= 100:
        interval_A = len(gene_A) - 50 * i
    else:
        interval_A = 100

    max_A = ''
    max_B = ''
    idx_A = 0
    idx_B = 0
    max_length = 0
    slice_A = gene_A[50 * i: 50 * i + interval_A]

    for j in range(floor(len(gene_B) / 50)):
        interval_B = 0
        if len(gene_B) - 50 * j <= 50:
            break
        elif 51 <= len(gene_B) - 50 * j <= 100:
            interval_B = len(gene_B) - 50 * j
        else:
            interval_B = 100

        slice_B = gene_B[50 * j: 50 * j + interval_B]
        lcs_a, lcs_b, length = find_lcs_of_two(slice_A, slice_B)
        if (length > max_length):
            max_A = lcs_a
            max_B = lcs_b
            idx_A = i
            idx_B = j
            max_length = length

    print('A' + str(idx_A * 50) + ',B' + str(idx_B * 50))
    print(max_A)
    print(max_B)


file_A.close()
file_B.close()

'''
X = "ABCBDAB"
Y = "BDCABA"
x, y = lcs_length(X, Y)
for line in x:
    print(line)
print('')
for line in y:
    print(line)

print(print_lcs(y, X, 7, 6, 1))
print(print_lcs(y, Y, 7, 6, 0))
'''
