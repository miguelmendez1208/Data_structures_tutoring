function insertionSort(nums: number[]){
    for(let i=1; i<nums.length;i++){
      let j = i;
      while(j>0 && nums[j-1] > nums[j]){
        let temp = nums[j];
        nums[j] = nums[j-1];
        nums[j-1] = temp;
        j--;
      }
    }
    return nums;
  }
  
  
  console.log(insertionSort([0, 5, -3, 7, -2]));
  