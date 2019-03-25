package main

import (
	"crypto/hmac"
	"crypto/sha256"
	"encoding/base64"
	"fmt"
	"io"
	"path/filepath"
)

func main() {
	fmt.Println("On Unix:")
	fmt.Println(filepath.Join("a", "b", "c"))
	fmt.Println(filepath.Join("a", "b/c"))
	fmt.Println(filepath.Join("a/b", "c"))
	fmt.Println(filepath.Join("a/b", "/c"))
	s := "heal the world, make it a better place"

	encodeStd := "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
	s64 := base64.NewEncoding(encodeStd).EncodeToString([]byte(s))
	fmt.Println("base64.NewEncoding(encodeStd).EncodeToString")
	fmt.Println(len(s))
	fmt.Println(len(s64))
	fmt.Println(s)
	fmt.Println(s64)
	s64_std := base64.StdEncoding.EncodeToString([]byte(s))
	fmt.Println("base64.StdEncoding.EncodeToString")
	fmt.Println(len(s))
	fmt.Println(len(s64_std))
	fmt.Println(s)
	fmt.Println(s64_std)

	c := getSha256Code("test@example.com")
	fmt.Println(c)

	c = getHmacCode("test@example.com")
	fmt.Println(c)
}

func getHmacCode(s string) string {
	h := hmac.New(sha256.New, []byte("ourkey"))
	io.WriteString(h, s)
	return fmt.Sprintf("%x", h.Sum(nil))
}

func getSha256Code(s string) string {
	h := sha256.New()
	h.Write([]byte(s))
	return fmt.Sprintf("%x", h.Sum(nil))

}
