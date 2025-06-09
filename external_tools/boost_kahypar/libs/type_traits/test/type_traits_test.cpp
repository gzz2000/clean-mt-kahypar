
//  (C) Copyright John Maddock 2010. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost_kahypar/type_traits.hpp>

//
// Just check that each trait actually exists, not
// that it gives the correct answer, we do that elsewhere:
//

typedef boost_kahypar::add_const<int>::type t1;
typedef boost_kahypar::add_cv<int>::type t2;
typedef boost_kahypar::add_lvalue_reference<int>::type t3;
typedef boost_kahypar::add_pointer<int>::type t4;
typedef boost_kahypar::add_reference<int>::type t5;
typedef boost_kahypar::add_rvalue_reference<int>::type t6;
typedef boost_kahypar::add_volatile<int>::type t7;

typedef boost_kahypar::aligned_storage<2>::type t8;
typedef boost_kahypar::alignment_of<int>::type t9;
typedef boost_kahypar::conditional<true, int, long>::type t10;
typedef boost_kahypar::common_type<int, long>::type t11;
typedef boost_kahypar::decay<int[2] >::type t12;
typedef boost_kahypar::extent<int[3] >::type t13;
typedef boost_kahypar::floating_point_promotion<int>::type t14;
typedef boost_kahypar::function_traits<int (int) > t15;

typedef boost_kahypar::has_new_operator<int> t16;
typedef boost_kahypar::has_nothrow_assign<int> t17;
typedef boost_kahypar::has_nothrow_constructor<int> t18;
typedef boost_kahypar::has_nothrow_copy<int> t19;
typedef boost_kahypar::has_nothrow_copy_constructor<int> t20;
typedef boost_kahypar::has_nothrow_default_constructor<int> t21;
typedef boost_kahypar::has_trivial_assign<int> t22;
typedef boost_kahypar::has_trivial_constructor<int> t23;
typedef boost_kahypar::has_trivial_copy<int> t24;
typedef boost_kahypar::has_trivial_copy_constructor<int> t25;
typedef boost_kahypar::has_trivial_default_constructor<int> t26;
typedef boost_kahypar::has_trivial_destructor<int> t27;
typedef boost_kahypar::has_virtual_destructor<int> t28;

typedef boost_kahypar::integral_constant<int, 2> t29;
typedef boost_kahypar::integral_promotion<short>::type t30;

typedef boost_kahypar::is_abstract<int>::type t31;
typedef boost_kahypar::is_arithmetic<int>::type t32;
typedef boost_kahypar::is_array<int>::type t33;
typedef boost_kahypar::is_base_of<int, long>::type t34;
typedef boost_kahypar::is_class<int>::type t35;
typedef boost_kahypar::is_complex<int>::type t36;
typedef boost_kahypar::is_compound<int>::type t37;
typedef boost_kahypar::is_const<int>::type t38;
typedef boost_kahypar::is_convertible<int, long>::type t39;
typedef boost_kahypar::is_empty<int>::type t40;
typedef boost_kahypar::is_enum<int>::type t41;
typedef boost_kahypar::is_floating_point<int>::type t42;
typedef boost_kahypar::is_function<int>::type t43;
typedef boost_kahypar::is_fundamental<int>::type t44;
typedef boost_kahypar::is_integral<int>::type t45;
typedef boost_kahypar::is_lvalue_reference<int>::type t46;
typedef boost_kahypar::is_member_function_pointer<int>::type t47;
typedef boost_kahypar::is_member_object_pointer<int>::type t48;
typedef boost_kahypar::is_member_pointer<int>::type t49;
typedef boost_kahypar::is_object<int>::type t50;
typedef boost_kahypar::is_pod<int>::type t51;
typedef boost_kahypar::is_pointer<int>::type t52;
typedef boost_kahypar::is_polymorphic<int>::type t53;
typedef boost_kahypar::is_reference<int>::type t54;
typedef boost_kahypar::is_rvalue_reference<int>::type t55;
typedef boost_kahypar::is_same<int, int>::type t56;
typedef boost_kahypar::is_scalar<int>::type t57;
typedef boost_kahypar::is_signed<int>::type t58;
typedef boost_kahypar::is_stateless<int>::type t59;
typedef boost_kahypar::is_union<int>::type t60;
typedef boost_kahypar::is_unsigned<int>::type t61;
typedef boost_kahypar::is_virtual_base_of<int, int>::type t62;
typedef boost_kahypar::is_void<int>::type t63;
typedef boost_kahypar::is_volatile<int>::type t64;
typedef boost_kahypar::make_signed<int>::type t65;
typedef boost_kahypar::make_unsigned<int>::type t66;
typedef boost_kahypar::promote<int>::type t67;
typedef boost_kahypar::rank<int>::type t68;

typedef boost_kahypar::remove_all_extents<int>::type t69;
typedef boost_kahypar::remove_const<int>::type t70;
typedef boost_kahypar::remove_cv<int>::type t71;
typedef boost_kahypar::remove_extent<int>::type t72;
typedef boost_kahypar::remove_pointer<int>::type t73;
typedef boost_kahypar::remove_reference<int>::type t74;
typedef boost_kahypar::remove_volatile<int>::type t75;
typedef boost_kahypar::type_with_alignment<4>::type t76;

int main()
{
   return 0;
}




