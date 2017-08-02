
#include <array>
template<typename IntType, int Start, int Skip, std::size_t... I>
	constexpr std::array<IntType, sizeof...(I)> SkipSequence_impl(std::index_sequence<I...>&&)
	{
		return { (static_cast<IntType>(Skip*I + Start))... };
	}

	template<typename IntType, int Start, int Skip, std::size_t Size, typename Indices = std::make_index_sequence<Size>>
	struct SkipSequence
	{
		static constexpr std::array<IntType, Size> value = SkipSequenceWithStart_impl<IntType,Start, Skip>(Indices());
	};