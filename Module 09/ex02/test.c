// Before: 6470 5686 1782 7325 4958 3646 4151 8388 8166 121 2694 9239 5683 4933 7356 1216 963 8864 8329 6829 4074 
// ========================================================
// ########################################################
// recurtion depth: 0
// number of comparaisons: 10
// vectorOfPairs size: 10
// vectorPair: {5686, 6470}{1782, 7325}{3646, 4958}{4151, 8388}{121, 8166}{2694, 9239}{4933, 5683}{1216, 7356}{963, 8864}{6829, 8329}
// rest: 4074
// ########################################################
// recurtion depth: 1
// number of comparaisons: 15
// vectorOfPairs size: 5
// vectorPair: {5686 6470, 1782 7325}{3646 4958, 4151 8388}{121 8166, 2694 9239}{4933 5683, 1216 7356}{6829 8329, 963 8864}
// rest: 
// ########################################################
// recurtion depth: 2
// number of comparaisons: 17
// vectorOfPairs size: 2
// vectorPair: {5686 6470 1782 7325, 3646 4958 4151 8388}{4933 5683 1216 7356, 121 8166 2694 9239}
// rest: 6829 8329 963 8864
// ########################################################
// recurtion depth: 3
// number of comparaisons: 18
// vectorOfPairs size: 1
// vectorPair: {5686 6470 1782 7325 3646 4958 4151 8388, 4933 5683 1216 7356 121 8166 2694 9239}
// rest: 
// ########################################################
// reverse recurtion depth: 3
// number of comparaisons: 18
// vectorOfPairs size: 1
// vectorPair: {5686 6470 1782 7325 3646 4958 4151 8388, 4933 5683 1216 7356 121 8166 2694 9239}
// mainChain: 5686 6470 1782 7325 3646 4958 4151 8388 , 4933 5683 1216 7356 121 8166 2694 9239
// pend: 
// rest: 
// Final mainChain: 5686 6470 1782 7325 3646 4958 4151 8388 , 4933 5683 1216 7356 121 8166 2694 9239
// ########################################################
// reverse recurtion depth: 2
// number of comparaisons: 18
// vectorOfPairs size: 2
// vectorPair: {5686 6470 1782 7325, 3646 4958 4151 8388}{4933 5683 1216 7356, 121 8166 2694 9239}
// mainChain: 5686 6470 1782 7325 , 3646 4958 4151 8388 , 121 8166 2694 9239
// pend: 4933 5683 1216 7356
// rest: 6829 8329 963 8864
// Final mainChain: 5686 6470 1782 7325 , 4933 5683 1216 7356 , 3646 4958 4151 8388 , 6829 8329 963 8864 , 121 8166 2694 9239
// ########################################################
// reverse recurtion depth: 1
// number of comparaisons: 22
// vectorOfPairs size: 5
// vectorPair: {5686 6470, 1782 7325}{4933 5683, 1216 7356}{3646 4958, 4151 8388}{6829 8329, 963 8864}{121 8166, 2694 9239}
// mainChain: 5686 6470 , 1782 7325 , 1216 7356 , 4151 8388 , 963 8864 , 2694 9239
// pend: 4933 5683 , 3646 4958 , 6829 8329 , 121 8166
// rest: 
// Final mainChain: 3646 4958 , 4933 5683 , 5686 6470 , 1782 7325 , 1216 7356 , 121 8166 , 6829 8329 , 4151 8388 , 963 8864 , 2694 9239
// ########################################################
// reverse recurtion depth: 0
// number of comparaisons: 34
// vectorOfPairs size: 10
// vectorPair: {3646, 4958}{4933, 5683}{5686, 6470}{1782, 7325}{1216, 7356}{121, 8166}{6829, 8329}{4151, 8388}{963, 8864}{2694, 9239}
// mainChain: 3646 , 4958 , 5683 , 6470 , 7325 , 7356 , 8166 , 8329 , 8388 , 8864 , 9239
// pend: 4933 , 5686 , 1782 , 1216 , 121 , 6829 , 4151 , 963 , 2694
// rest: 4074
// Final mainChain: 121 , 963 , 1216 , 1782 , 2694 , 3646 , 4074 , 4151 , 4933 , 4958 , 5683 , 5686 , 6470 , 6829 , 7325 , 7356 , 8166 , 8329 , 8388 , 8864 , 9239
// ========================================================
// After: 121 963 1216 1782 2694 3646 4074 4151 4933 4958 5683 5686 6470 6829 7325 7356 8166 8329 8388 8864 9239 
// Number of comparaison: 74