# ALGORITMO BUBBLESORT

def bubble_sort(itens):
	n = len(itens)
	for i in range(n):
		for x in range(n - 1):
			A = itens[x]
			B = itens[x + 1]
			C = None

			if A > B:
				C = A
				A = B
				B = C

			itens[x] = A
			itens[x + 1] = B

exemplo = [1, 2, 4, 5, 6, 7, 2, 6, 9, 29, 92, 90, 3, 12, 88, 5, 3, 8, 2]

bubble_sort(exemplo)
print (exemplo)
 
