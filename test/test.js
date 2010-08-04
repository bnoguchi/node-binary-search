#!/usr/bin/env node
var assert = require("assert"),
    bsearch = require("../build/default/binarySearch").binarySearch;
arr = [11,12,13,14,15,16,17,18,19,20];
var index = bsearch(arr, 16);
assert.equal(arr[index], 16);
