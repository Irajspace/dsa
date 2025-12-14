Problem link-[Stickers to Spell Word (LeetCode)](https://leetcode.com/problems/stickers-to-spell-word/description/?envType=problem-list-v2&envId=bitmask)

first of all what does 
1<<n mean (111111...11)n times ok


Observations
1) Problem coming

    a) where to loop through (i.e mask) in which mask is better to consider whether to loop through stickers or target
    b) Think is it feasible to loop through stickers 
    c) We want to the target to be complete so we have to consider mask of target only
    d) dp[mask]= min no of stickers required to complete the mask
    e) now you have stickers for each stickers 
       you can move through each sticker once 
       for each character of that sticker see is it matching with the target character
       if it matches break
    f) now new_mask will min(new_mask,mask+1)
