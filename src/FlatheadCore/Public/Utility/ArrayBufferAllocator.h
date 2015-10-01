
#include "v8.h"

using namespace v8;

namespace Gneu
{
	namespace Utility
	{
		class ArrayBufferAllocator : public ArrayBuffer::Allocator
		{
		public:
			virtual void* Allocate(size_t length);
			virtual void* AllocateUninitialized(size_t length);

			virtual void Free(void* data, size_t);
		};
	}
}