cc_binary(
    name = "hello_world",
    srcs = ["hello_world.cc"],
    deps = [
        "@com_google_tcmalloc//tcmalloc:malloc_extension",
        "@com_google_absl//absl/strings",
        "@com_google_absl//absl/strings:str_format",
        "@com_google_absl//absl/types:optional",
    ],
    malloc = "@com_google_tcmalloc//tcmalloc",
)
