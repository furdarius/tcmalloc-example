#include <iostream>
#include <cstddef>

#include "absl/strings/str_cat.h"
#include "absl/strings/str_format.h"
#include "absl/types/optional.h"
#include "tcmalloc/malloc_extension.h"

void testtcmalloc() {
	std::cout << "TESTTCMALLOC" << std::endl;

  absl::optional<size_t> heap_size =
      tcmalloc::MallocExtension::GetNumericProperty(
          "generic.current_allocated_bytes");
  if (heap_size.has_value()) {
	  std::cout << "Current heap size = " << *heap_size << " bytes" << std::endl;
  }

  // Allocate memory, printing the pointer to deter an optimizing compiler from
  // eliding the allocation.
  constexpr size_t kSize = 1024 * 1024 * 1024;
  std::unique_ptr<char[]> ptr(new char[kSize]);

  heap_size = tcmalloc::MallocExtension::GetNumericProperty(
      "generic.current_allocated_bytes");
  if (heap_size.has_value()) {
	  std::cout << "Current heap size = " << *heap_size << " bytes" << std::endl;
  }

  void* ptr2 = malloc(kSize);

  heap_size = tcmalloc::MallocExtension::GetNumericProperty(
      "generic.current_allocated_bytes");
  if (heap_size.has_value()) {
	  std::cout << "Current heap size = " << *heap_size << " bytes" << std::endl;
  }

  free(ptr2);
}

int main() {
    std::cout << "Standard Alignment: " << alignof(std::max_align_t) << '\n';

    double *ptr = (double*) malloc(sizeof(double));
    std::cout << "Double Alignment: " << alignof(*ptr) << '\n';

    char *ptr2 = (char*) malloc(1);
    std::cout << "Char Alignment: " << alignof(*ptr2) << '\n';

    void *ptr3;
    std::cout << "Sizeof void*: " << sizeof(ptr3) << '\n';

    testtcmalloc();

    return 0;
}
