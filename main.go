package brotli

import (
	"github.com/laysakura/brotli-go/shared"
	"github.com/laysakura/brotli-go/dec"
	"github.com/laysakura/brotli-go/enc"
)

var _ = shared.GetDictionary
var _ = dec.DecompressBuffer
var _ = enc.CompressBuffer
