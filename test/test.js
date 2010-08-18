#!/usr/bin/env node
var assert = require("assert"),
    bsearch = require("../lib/binarySearch").binarySearch,
    fbsearch = require("../lib/binarySearch").floorBinarySearch,
    cbsearch = require("../lib/binarySearch").ceilingBinarySearch,
    
    arr = [11,12,13,14,15,16,17,18,19,20];

// Test Binary Search
var index = bsearch(arr, 16);
assert.equal(arr[index], 16);

index = bsearch(arr, 21);
assert.equal(index, -1);

index = bsearch(arr, 10);
assert.equal(index, -1);

arr = [4, 6, 8];

// Test Floor Binary Search
index = fbsearch(arr, 4);
assert.equal(index, 0);

index = fbsearch(arr, 5);
assert.equal(index, 0);

index = fbsearch(arr, 7);
assert.equal(index, 1);

index = fbsearch(arr, 9);
assert.equal(index, 2);

index = fbsearch(arr, 0);
assert.equal(index, 2);

// Test Ceiling Binary Search
index = cbsearch(arr, 4);
assert.equal(index, 0);

index = cbsearch(arr, 5);
assert.equal(index, 1);

index = cbsearch(arr, 7);
assert.equal(index, 2);

index = cbsearch(arr, 9);
assert.equal(index, 0);

index = cbsearch(arr, 0);
assert.equal(index, 0);
