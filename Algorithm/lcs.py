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

slice_A0 = gene_A[0:100]
slice_B0 = gene_B[0:100]

x, y = lcs_length(slice_A0, slice_B0)

lcs_A = print_lcs(y, slice_A0, 100, 100, 1)
lcs_B = print_lcs(y, slice_B0, 100, 100, 0)

lcs_A = '_' * (len(slice_A0) - len(lcs_A)) + lcs_A
lcs_B = '_' * (len(slice_B0) - len(lcs_B)) + lcs_B
print(slice_A0)
print(lcs_A)
print(slice_B0)
print(lcs_B)
# for line in geneA:
#    print(line)
# print(gene_A)

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
