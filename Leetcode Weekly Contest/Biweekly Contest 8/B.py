class Solution:
	def beforeAndAfterPuzzles(self, phrases: List[str]) -> List[str]:
		ans = []
		# print(len(phrases))
		for i in range(len(phrases)):
			# print("=======")
			# print(i)
			for j in range(len(phrases)):
				if (i == j):
					continue
				# print(len(phrases))
				# print(j)
				s = phrases[i]
				t = phrases[j]
				# print(s)
				# print(t)
				words = s.split(' ')
				wordt = t.split(' ')
				# print(words)
				# print(wordt)
				if (words[-1] == wordt[0]):
					newt = ' '.join(wordt[1:])
					# print(newt)
					if (len(wordt) != 1):
						news = ' '.join([s, newt])
					else:
						news = s
					ans.append(news)
		ans = list(set(ans))
		ans = sorted(ans)
		return ans



