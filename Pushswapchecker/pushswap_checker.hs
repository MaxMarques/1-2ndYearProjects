import System.Environment
import Control.Monad

swapSa :: [a] -> [a]
swapSa [] = []
swapSa [a] = [a]
swapSa (a:b:as) = b:a:as

swapSb :: [a] -> [a]
swapSb [] = []
swapSb [b] = [b]
swapSb (b:a:bs) = a:b:bs

takePa :: ([a], [a]) -> ([a], [a])
takePa ([], []) = ([], [])
takePa (a, []) = (a, [])
takePa (a, b:bs) = (b:a, bs)

takePb :: ([a], [a]) -> ([a], [a])
takePb ([], []) = ([], [])
takePb ([], b) = ([], b)
takePb (a:as, b) = (as, a:b)

rotateRa :: [a] -> [a]
rotateRa [] = []
rotateRa (a:as) = as ++ [a]

rotateRb :: [b] -> [b]
rotateRb [] = []
rotateRb (b:bs) = bs ++ [b]

rotateRra :: [a] -> [a]
rotateRra [] = []
rotateRra a = last a : (init . tail $ a) ++ [head a]

rotateRrb :: [b] -> [b]
rotateRrb [] = []
rotateRrb b = last b : (init.tail $ b) ++ [head b]

doOp :: [String] -> ([a], [a]) -> ([a], [a])
doOp [] t = t
doOp ("sa":xs) (a, b) = doOp xs (swapSa a, b)
doOp ("sb":xs) (a, b) = doOp xs (a, swapSb b)
doOp ("sc":xs) (a, b) = doOp xs (swapSa a, swapSb b)
doOp ("pa":xs) (a, b) = doOp xs (takePa (a, b))
doOp ("pb":xs) (a, b) = doOp xs (takePb (a, b))
doOp ("ra":xs) (a, b) = doOp xs (rotateRa a, b)
doOp ("rb":xs) (a, b) = doOp xs (a, rotateRb b)
doOp ("rr":xs) (a, b) = doOp xs (rotateRa a, rotateRb b)
doOp ("rra":xs) (a, b) = doOp xs (rotateRra a, b)
doOp ("rrb":xs) (a, b) = doOp xs (a, rotateRrb b)
doOp ("rrr":xs) (a, b) = doOp xs (rotateRra a, rotateRrb b)
doOp (_:xs) t = doOp xs t

isSorted :: [Int] -> Bool
isSorted [] = True
isSorted [a] = True
isSorted (a:b:xs)
    | a > b = False
    | otherwise = isSorted xs

main :: IO ()
main = do
    str <- getLine 
    nbr <- getArgs
    let wrd = words str
    let list = map (read :: String -> Int) nbr
    let operation = doOp wrd (list, [])
    when (isSorted list) (putStrLn "OK")
    putStrLn "KO"