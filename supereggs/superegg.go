package main

type singleCase struct {
	K int
	N int
}

var booking map[singleCase]int = make(map[singleCase]int)

func superEggDrop(K int, N int) int {
	if K == 1 {
		return N
	}
	if N == 0 {
		return 0
	}
	value, ok := booking[singleCase{K, N}]
	if ok {
		return value
	}
	var totalCount int
	for i := 1; i <= N; i++ {
		var badSituation int
		if superEggDrop(K-1, i-1) > superEggDrop(K, N-i) {
			badSituation = superEggDrop(K-1, i-1) + 1
			if totalCount > badSituation || totalCount == 0 {
				totalCount = badSituation
			}

		} else {
			badSituation = superEggDrop(K, N-i) + 1
			if totalCount > badSituation || totalCount == 0 {
				totalCount = badSituation
			}
		}

	}
	booking[singleCase{K, N}] = totalCount
	return totalCount
}
