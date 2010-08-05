#!/usr/bin/env node
var assert = require("assert"),
    bsearch = require("binarySearch").binarySearch;
arr = [11,12,13,14,15,16,17,18,19,20];

var index = bsearch(arr, 16);
assert.equal(arr[index], 16);

index = bsearch(arr, 21);
assert.equal(index, -1);

index = bsearch(arr, 10);
assert.equal(index, -1);
