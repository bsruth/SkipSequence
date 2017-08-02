
#include <array>
//lets me have a compile time sequence with a custom starting value and increment
//e.g. 
template<typename IntType, IntType Start, IntType Skip, IntType... I>
constexpr std::array<IntType, sizeof...(I)> SkipSequence_impl(std::index_sequence<I...>&&)
{
	return { (Skip * I + Start)... };
}

template<typename IntType, IntType Start, IntType Skip, IntType Size, typename Indices = std::make_index_sequence<Size>>
struct SkipSequence
{
	static constexpr std::array<IntType, Size> value = SkipSequence_impl<IntType, Start, Skip>(Indices());
};