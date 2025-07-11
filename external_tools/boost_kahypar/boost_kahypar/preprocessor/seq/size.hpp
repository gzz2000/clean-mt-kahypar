# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Paul Mensonides 2002.
#  *     Distributed under the Boost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.boost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* Revised by Edward Diener (2020) */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef BOOST_PREPROCESSOR_SEQ_SIZE_HPP
# define BOOST_PREPROCESSOR_SEQ_SIZE_HPP
#
# include <boost_kahypar/preprocessor/cat.hpp>
# include <boost_kahypar/preprocessor/config/config.hpp>
#
# if BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_MWCC()
#    define BOOST_PP_SEQ_SIZE(seq) BOOST_PP_SEQ_SIZE_I((seq))
#    define BOOST_PP_SEQ_SIZE_I(par) BOOST_PP_SEQ_SIZE_II ## par
#    define BOOST_PP_SEQ_SIZE_II(seq) BOOST_PP_CAT(BOOST_PP_SEQ_SIZE_, BOOST_PP_SEQ_SIZE_0 ## seq)
# elif BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_EDG() || BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_MSVC()
#    define BOOST_PP_SEQ_SIZE(seq) BOOST_PP_SEQ_SIZE_I(seq)
#    define BOOST_PP_SEQ_SIZE_I(seq) BOOST_PP_CAT(BOOST_PP_SEQ_SIZE_, BOOST_PP_SEQ_SIZE_0 seq)
# elif defined(__IBMC__) || defined(__IBMCPP__)
#    define BOOST_PP_SEQ_SIZE(seq) BOOST_PP_CAT(BOOST_PP_SEQ_SIZE_, BOOST_PP_CAT(BOOST_PP_SEQ_SIZE_0, seq))
# else
#    define BOOST_PP_SEQ_SIZE(seq) BOOST_PP_CAT(BOOST_PP_SEQ_SIZE_, BOOST_PP_SEQ_SIZE_0 seq)
# endif
#
# if ~BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_STRICT()
#
# define BOOST_PP_SEQ_SIZE_0(_) BOOST_PP_SEQ_SIZE_1
# define BOOST_PP_SEQ_SIZE_1(_) BOOST_PP_SEQ_SIZE_2
# define BOOST_PP_SEQ_SIZE_2(_) BOOST_PP_SEQ_SIZE_3
# define BOOST_PP_SEQ_SIZE_3(_) BOOST_PP_SEQ_SIZE_4
# define BOOST_PP_SEQ_SIZE_4(_) BOOST_PP_SEQ_SIZE_5
# define BOOST_PP_SEQ_SIZE_5(_) BOOST_PP_SEQ_SIZE_6
# define BOOST_PP_SEQ_SIZE_6(_) BOOST_PP_SEQ_SIZE_7
# define BOOST_PP_SEQ_SIZE_7(_) BOOST_PP_SEQ_SIZE_8
# define BOOST_PP_SEQ_SIZE_8(_) BOOST_PP_SEQ_SIZE_9
# define BOOST_PP_SEQ_SIZE_9(_) BOOST_PP_SEQ_SIZE_10
# define BOOST_PP_SEQ_SIZE_10(_) BOOST_PP_SEQ_SIZE_11
# define BOOST_PP_SEQ_SIZE_11(_) BOOST_PP_SEQ_SIZE_12
# define BOOST_PP_SEQ_SIZE_12(_) BOOST_PP_SEQ_SIZE_13
# define BOOST_PP_SEQ_SIZE_13(_) BOOST_PP_SEQ_SIZE_14
# define BOOST_PP_SEQ_SIZE_14(_) BOOST_PP_SEQ_SIZE_15
# define BOOST_PP_SEQ_SIZE_15(_) BOOST_PP_SEQ_SIZE_16
# define BOOST_PP_SEQ_SIZE_16(_) BOOST_PP_SEQ_SIZE_17
# define BOOST_PP_SEQ_SIZE_17(_) BOOST_PP_SEQ_SIZE_18
# define BOOST_PP_SEQ_SIZE_18(_) BOOST_PP_SEQ_SIZE_19
# define BOOST_PP_SEQ_SIZE_19(_) BOOST_PP_SEQ_SIZE_20
# define BOOST_PP_SEQ_SIZE_20(_) BOOST_PP_SEQ_SIZE_21
# define BOOST_PP_SEQ_SIZE_21(_) BOOST_PP_SEQ_SIZE_22
# define BOOST_PP_SEQ_SIZE_22(_) BOOST_PP_SEQ_SIZE_23
# define BOOST_PP_SEQ_SIZE_23(_) BOOST_PP_SEQ_SIZE_24
# define BOOST_PP_SEQ_SIZE_24(_) BOOST_PP_SEQ_SIZE_25
# define BOOST_PP_SEQ_SIZE_25(_) BOOST_PP_SEQ_SIZE_26
# define BOOST_PP_SEQ_SIZE_26(_) BOOST_PP_SEQ_SIZE_27
# define BOOST_PP_SEQ_SIZE_27(_) BOOST_PP_SEQ_SIZE_28
# define BOOST_PP_SEQ_SIZE_28(_) BOOST_PP_SEQ_SIZE_29
# define BOOST_PP_SEQ_SIZE_29(_) BOOST_PP_SEQ_SIZE_30
# define BOOST_PP_SEQ_SIZE_30(_) BOOST_PP_SEQ_SIZE_31
# define BOOST_PP_SEQ_SIZE_31(_) BOOST_PP_SEQ_SIZE_32
# define BOOST_PP_SEQ_SIZE_32(_) BOOST_PP_SEQ_SIZE_33
# define BOOST_PP_SEQ_SIZE_33(_) BOOST_PP_SEQ_SIZE_34
# define BOOST_PP_SEQ_SIZE_34(_) BOOST_PP_SEQ_SIZE_35
# define BOOST_PP_SEQ_SIZE_35(_) BOOST_PP_SEQ_SIZE_36
# define BOOST_PP_SEQ_SIZE_36(_) BOOST_PP_SEQ_SIZE_37
# define BOOST_PP_SEQ_SIZE_37(_) BOOST_PP_SEQ_SIZE_38
# define BOOST_PP_SEQ_SIZE_38(_) BOOST_PP_SEQ_SIZE_39
# define BOOST_PP_SEQ_SIZE_39(_) BOOST_PP_SEQ_SIZE_40
# define BOOST_PP_SEQ_SIZE_40(_) BOOST_PP_SEQ_SIZE_41
# define BOOST_PP_SEQ_SIZE_41(_) BOOST_PP_SEQ_SIZE_42
# define BOOST_PP_SEQ_SIZE_42(_) BOOST_PP_SEQ_SIZE_43
# define BOOST_PP_SEQ_SIZE_43(_) BOOST_PP_SEQ_SIZE_44
# define BOOST_PP_SEQ_SIZE_44(_) BOOST_PP_SEQ_SIZE_45
# define BOOST_PP_SEQ_SIZE_45(_) BOOST_PP_SEQ_SIZE_46
# define BOOST_PP_SEQ_SIZE_46(_) BOOST_PP_SEQ_SIZE_47
# define BOOST_PP_SEQ_SIZE_47(_) BOOST_PP_SEQ_SIZE_48
# define BOOST_PP_SEQ_SIZE_48(_) BOOST_PP_SEQ_SIZE_49
# define BOOST_PP_SEQ_SIZE_49(_) BOOST_PP_SEQ_SIZE_50
# define BOOST_PP_SEQ_SIZE_50(_) BOOST_PP_SEQ_SIZE_51
# define BOOST_PP_SEQ_SIZE_51(_) BOOST_PP_SEQ_SIZE_52
# define BOOST_PP_SEQ_SIZE_52(_) BOOST_PP_SEQ_SIZE_53
# define BOOST_PP_SEQ_SIZE_53(_) BOOST_PP_SEQ_SIZE_54
# define BOOST_PP_SEQ_SIZE_54(_) BOOST_PP_SEQ_SIZE_55
# define BOOST_PP_SEQ_SIZE_55(_) BOOST_PP_SEQ_SIZE_56
# define BOOST_PP_SEQ_SIZE_56(_) BOOST_PP_SEQ_SIZE_57
# define BOOST_PP_SEQ_SIZE_57(_) BOOST_PP_SEQ_SIZE_58
# define BOOST_PP_SEQ_SIZE_58(_) BOOST_PP_SEQ_SIZE_59
# define BOOST_PP_SEQ_SIZE_59(_) BOOST_PP_SEQ_SIZE_60
# define BOOST_PP_SEQ_SIZE_60(_) BOOST_PP_SEQ_SIZE_61
# define BOOST_PP_SEQ_SIZE_61(_) BOOST_PP_SEQ_SIZE_62
# define BOOST_PP_SEQ_SIZE_62(_) BOOST_PP_SEQ_SIZE_63
# define BOOST_PP_SEQ_SIZE_63(_) BOOST_PP_SEQ_SIZE_64
# define BOOST_PP_SEQ_SIZE_64(_) BOOST_PP_SEQ_SIZE_65
# define BOOST_PP_SEQ_SIZE_65(_) BOOST_PP_SEQ_SIZE_66
# define BOOST_PP_SEQ_SIZE_66(_) BOOST_PP_SEQ_SIZE_67
# define BOOST_PP_SEQ_SIZE_67(_) BOOST_PP_SEQ_SIZE_68
# define BOOST_PP_SEQ_SIZE_68(_) BOOST_PP_SEQ_SIZE_69
# define BOOST_PP_SEQ_SIZE_69(_) BOOST_PP_SEQ_SIZE_70
# define BOOST_PP_SEQ_SIZE_70(_) BOOST_PP_SEQ_SIZE_71
# define BOOST_PP_SEQ_SIZE_71(_) BOOST_PP_SEQ_SIZE_72
# define BOOST_PP_SEQ_SIZE_72(_) BOOST_PP_SEQ_SIZE_73
# define BOOST_PP_SEQ_SIZE_73(_) BOOST_PP_SEQ_SIZE_74
# define BOOST_PP_SEQ_SIZE_74(_) BOOST_PP_SEQ_SIZE_75
# define BOOST_PP_SEQ_SIZE_75(_) BOOST_PP_SEQ_SIZE_76
# define BOOST_PP_SEQ_SIZE_76(_) BOOST_PP_SEQ_SIZE_77
# define BOOST_PP_SEQ_SIZE_77(_) BOOST_PP_SEQ_SIZE_78
# define BOOST_PP_SEQ_SIZE_78(_) BOOST_PP_SEQ_SIZE_79
# define BOOST_PP_SEQ_SIZE_79(_) BOOST_PP_SEQ_SIZE_80
# define BOOST_PP_SEQ_SIZE_80(_) BOOST_PP_SEQ_SIZE_81
# define BOOST_PP_SEQ_SIZE_81(_) BOOST_PP_SEQ_SIZE_82
# define BOOST_PP_SEQ_SIZE_82(_) BOOST_PP_SEQ_SIZE_83
# define BOOST_PP_SEQ_SIZE_83(_) BOOST_PP_SEQ_SIZE_84
# define BOOST_PP_SEQ_SIZE_84(_) BOOST_PP_SEQ_SIZE_85
# define BOOST_PP_SEQ_SIZE_85(_) BOOST_PP_SEQ_SIZE_86
# define BOOST_PP_SEQ_SIZE_86(_) BOOST_PP_SEQ_SIZE_87
# define BOOST_PP_SEQ_SIZE_87(_) BOOST_PP_SEQ_SIZE_88
# define BOOST_PP_SEQ_SIZE_88(_) BOOST_PP_SEQ_SIZE_89
# define BOOST_PP_SEQ_SIZE_89(_) BOOST_PP_SEQ_SIZE_90
# define BOOST_PP_SEQ_SIZE_90(_) BOOST_PP_SEQ_SIZE_91
# define BOOST_PP_SEQ_SIZE_91(_) BOOST_PP_SEQ_SIZE_92
# define BOOST_PP_SEQ_SIZE_92(_) BOOST_PP_SEQ_SIZE_93
# define BOOST_PP_SEQ_SIZE_93(_) BOOST_PP_SEQ_SIZE_94
# define BOOST_PP_SEQ_SIZE_94(_) BOOST_PP_SEQ_SIZE_95
# define BOOST_PP_SEQ_SIZE_95(_) BOOST_PP_SEQ_SIZE_96
# define BOOST_PP_SEQ_SIZE_96(_) BOOST_PP_SEQ_SIZE_97
# define BOOST_PP_SEQ_SIZE_97(_) BOOST_PP_SEQ_SIZE_98
# define BOOST_PP_SEQ_SIZE_98(_) BOOST_PP_SEQ_SIZE_99
# define BOOST_PP_SEQ_SIZE_99(_) BOOST_PP_SEQ_SIZE_100
# define BOOST_PP_SEQ_SIZE_100(_) BOOST_PP_SEQ_SIZE_101
# define BOOST_PP_SEQ_SIZE_101(_) BOOST_PP_SEQ_SIZE_102
# define BOOST_PP_SEQ_SIZE_102(_) BOOST_PP_SEQ_SIZE_103
# define BOOST_PP_SEQ_SIZE_103(_) BOOST_PP_SEQ_SIZE_104
# define BOOST_PP_SEQ_SIZE_104(_) BOOST_PP_SEQ_SIZE_105
# define BOOST_PP_SEQ_SIZE_105(_) BOOST_PP_SEQ_SIZE_106
# define BOOST_PP_SEQ_SIZE_106(_) BOOST_PP_SEQ_SIZE_107
# define BOOST_PP_SEQ_SIZE_107(_) BOOST_PP_SEQ_SIZE_108
# define BOOST_PP_SEQ_SIZE_108(_) BOOST_PP_SEQ_SIZE_109
# define BOOST_PP_SEQ_SIZE_109(_) BOOST_PP_SEQ_SIZE_110
# define BOOST_PP_SEQ_SIZE_110(_) BOOST_PP_SEQ_SIZE_111
# define BOOST_PP_SEQ_SIZE_111(_) BOOST_PP_SEQ_SIZE_112
# define BOOST_PP_SEQ_SIZE_112(_) BOOST_PP_SEQ_SIZE_113
# define BOOST_PP_SEQ_SIZE_113(_) BOOST_PP_SEQ_SIZE_114
# define BOOST_PP_SEQ_SIZE_114(_) BOOST_PP_SEQ_SIZE_115
# define BOOST_PP_SEQ_SIZE_115(_) BOOST_PP_SEQ_SIZE_116
# define BOOST_PP_SEQ_SIZE_116(_) BOOST_PP_SEQ_SIZE_117
# define BOOST_PP_SEQ_SIZE_117(_) BOOST_PP_SEQ_SIZE_118
# define BOOST_PP_SEQ_SIZE_118(_) BOOST_PP_SEQ_SIZE_119
# define BOOST_PP_SEQ_SIZE_119(_) BOOST_PP_SEQ_SIZE_120
# define BOOST_PP_SEQ_SIZE_120(_) BOOST_PP_SEQ_SIZE_121
# define BOOST_PP_SEQ_SIZE_121(_) BOOST_PP_SEQ_SIZE_122
# define BOOST_PP_SEQ_SIZE_122(_) BOOST_PP_SEQ_SIZE_123
# define BOOST_PP_SEQ_SIZE_123(_) BOOST_PP_SEQ_SIZE_124
# define BOOST_PP_SEQ_SIZE_124(_) BOOST_PP_SEQ_SIZE_125
# define BOOST_PP_SEQ_SIZE_125(_) BOOST_PP_SEQ_SIZE_126
# define BOOST_PP_SEQ_SIZE_126(_) BOOST_PP_SEQ_SIZE_127
# define BOOST_PP_SEQ_SIZE_127(_) BOOST_PP_SEQ_SIZE_128
# define BOOST_PP_SEQ_SIZE_128(_) BOOST_PP_SEQ_SIZE_129
# define BOOST_PP_SEQ_SIZE_129(_) BOOST_PP_SEQ_SIZE_130
# define BOOST_PP_SEQ_SIZE_130(_) BOOST_PP_SEQ_SIZE_131
# define BOOST_PP_SEQ_SIZE_131(_) BOOST_PP_SEQ_SIZE_132
# define BOOST_PP_SEQ_SIZE_132(_) BOOST_PP_SEQ_SIZE_133
# define BOOST_PP_SEQ_SIZE_133(_) BOOST_PP_SEQ_SIZE_134
# define BOOST_PP_SEQ_SIZE_134(_) BOOST_PP_SEQ_SIZE_135
# define BOOST_PP_SEQ_SIZE_135(_) BOOST_PP_SEQ_SIZE_136
# define BOOST_PP_SEQ_SIZE_136(_) BOOST_PP_SEQ_SIZE_137
# define BOOST_PP_SEQ_SIZE_137(_) BOOST_PP_SEQ_SIZE_138
# define BOOST_PP_SEQ_SIZE_138(_) BOOST_PP_SEQ_SIZE_139
# define BOOST_PP_SEQ_SIZE_139(_) BOOST_PP_SEQ_SIZE_140
# define BOOST_PP_SEQ_SIZE_140(_) BOOST_PP_SEQ_SIZE_141
# define BOOST_PP_SEQ_SIZE_141(_) BOOST_PP_SEQ_SIZE_142
# define BOOST_PP_SEQ_SIZE_142(_) BOOST_PP_SEQ_SIZE_143
# define BOOST_PP_SEQ_SIZE_143(_) BOOST_PP_SEQ_SIZE_144
# define BOOST_PP_SEQ_SIZE_144(_) BOOST_PP_SEQ_SIZE_145
# define BOOST_PP_SEQ_SIZE_145(_) BOOST_PP_SEQ_SIZE_146
# define BOOST_PP_SEQ_SIZE_146(_) BOOST_PP_SEQ_SIZE_147
# define BOOST_PP_SEQ_SIZE_147(_) BOOST_PP_SEQ_SIZE_148
# define BOOST_PP_SEQ_SIZE_148(_) BOOST_PP_SEQ_SIZE_149
# define BOOST_PP_SEQ_SIZE_149(_) BOOST_PP_SEQ_SIZE_150
# define BOOST_PP_SEQ_SIZE_150(_) BOOST_PP_SEQ_SIZE_151
# define BOOST_PP_SEQ_SIZE_151(_) BOOST_PP_SEQ_SIZE_152
# define BOOST_PP_SEQ_SIZE_152(_) BOOST_PP_SEQ_SIZE_153
# define BOOST_PP_SEQ_SIZE_153(_) BOOST_PP_SEQ_SIZE_154
# define BOOST_PP_SEQ_SIZE_154(_) BOOST_PP_SEQ_SIZE_155
# define BOOST_PP_SEQ_SIZE_155(_) BOOST_PP_SEQ_SIZE_156
# define BOOST_PP_SEQ_SIZE_156(_) BOOST_PP_SEQ_SIZE_157
# define BOOST_PP_SEQ_SIZE_157(_) BOOST_PP_SEQ_SIZE_158
# define BOOST_PP_SEQ_SIZE_158(_) BOOST_PP_SEQ_SIZE_159
# define BOOST_PP_SEQ_SIZE_159(_) BOOST_PP_SEQ_SIZE_160
# define BOOST_PP_SEQ_SIZE_160(_) BOOST_PP_SEQ_SIZE_161
# define BOOST_PP_SEQ_SIZE_161(_) BOOST_PP_SEQ_SIZE_162
# define BOOST_PP_SEQ_SIZE_162(_) BOOST_PP_SEQ_SIZE_163
# define BOOST_PP_SEQ_SIZE_163(_) BOOST_PP_SEQ_SIZE_164
# define BOOST_PP_SEQ_SIZE_164(_) BOOST_PP_SEQ_SIZE_165
# define BOOST_PP_SEQ_SIZE_165(_) BOOST_PP_SEQ_SIZE_166
# define BOOST_PP_SEQ_SIZE_166(_) BOOST_PP_SEQ_SIZE_167
# define BOOST_PP_SEQ_SIZE_167(_) BOOST_PP_SEQ_SIZE_168
# define BOOST_PP_SEQ_SIZE_168(_) BOOST_PP_SEQ_SIZE_169
# define BOOST_PP_SEQ_SIZE_169(_) BOOST_PP_SEQ_SIZE_170
# define BOOST_PP_SEQ_SIZE_170(_) BOOST_PP_SEQ_SIZE_171
# define BOOST_PP_SEQ_SIZE_171(_) BOOST_PP_SEQ_SIZE_172
# define BOOST_PP_SEQ_SIZE_172(_) BOOST_PP_SEQ_SIZE_173
# define BOOST_PP_SEQ_SIZE_173(_) BOOST_PP_SEQ_SIZE_174
# define BOOST_PP_SEQ_SIZE_174(_) BOOST_PP_SEQ_SIZE_175
# define BOOST_PP_SEQ_SIZE_175(_) BOOST_PP_SEQ_SIZE_176
# define BOOST_PP_SEQ_SIZE_176(_) BOOST_PP_SEQ_SIZE_177
# define BOOST_PP_SEQ_SIZE_177(_) BOOST_PP_SEQ_SIZE_178
# define BOOST_PP_SEQ_SIZE_178(_) BOOST_PP_SEQ_SIZE_179
# define BOOST_PP_SEQ_SIZE_179(_) BOOST_PP_SEQ_SIZE_180
# define BOOST_PP_SEQ_SIZE_180(_) BOOST_PP_SEQ_SIZE_181
# define BOOST_PP_SEQ_SIZE_181(_) BOOST_PP_SEQ_SIZE_182
# define BOOST_PP_SEQ_SIZE_182(_) BOOST_PP_SEQ_SIZE_183
# define BOOST_PP_SEQ_SIZE_183(_) BOOST_PP_SEQ_SIZE_184
# define BOOST_PP_SEQ_SIZE_184(_) BOOST_PP_SEQ_SIZE_185
# define BOOST_PP_SEQ_SIZE_185(_) BOOST_PP_SEQ_SIZE_186
# define BOOST_PP_SEQ_SIZE_186(_) BOOST_PP_SEQ_SIZE_187
# define BOOST_PP_SEQ_SIZE_187(_) BOOST_PP_SEQ_SIZE_188
# define BOOST_PP_SEQ_SIZE_188(_) BOOST_PP_SEQ_SIZE_189
# define BOOST_PP_SEQ_SIZE_189(_) BOOST_PP_SEQ_SIZE_190
# define BOOST_PP_SEQ_SIZE_190(_) BOOST_PP_SEQ_SIZE_191
# define BOOST_PP_SEQ_SIZE_191(_) BOOST_PP_SEQ_SIZE_192
# define BOOST_PP_SEQ_SIZE_192(_) BOOST_PP_SEQ_SIZE_193
# define BOOST_PP_SEQ_SIZE_193(_) BOOST_PP_SEQ_SIZE_194
# define BOOST_PP_SEQ_SIZE_194(_) BOOST_PP_SEQ_SIZE_195
# define BOOST_PP_SEQ_SIZE_195(_) BOOST_PP_SEQ_SIZE_196
# define BOOST_PP_SEQ_SIZE_196(_) BOOST_PP_SEQ_SIZE_197
# define BOOST_PP_SEQ_SIZE_197(_) BOOST_PP_SEQ_SIZE_198
# define BOOST_PP_SEQ_SIZE_198(_) BOOST_PP_SEQ_SIZE_199
# define BOOST_PP_SEQ_SIZE_199(_) BOOST_PP_SEQ_SIZE_200
# define BOOST_PP_SEQ_SIZE_200(_) BOOST_PP_SEQ_SIZE_201
# define BOOST_PP_SEQ_SIZE_201(_) BOOST_PP_SEQ_SIZE_202
# define BOOST_PP_SEQ_SIZE_202(_) BOOST_PP_SEQ_SIZE_203
# define BOOST_PP_SEQ_SIZE_203(_) BOOST_PP_SEQ_SIZE_204
# define BOOST_PP_SEQ_SIZE_204(_) BOOST_PP_SEQ_SIZE_205
# define BOOST_PP_SEQ_SIZE_205(_) BOOST_PP_SEQ_SIZE_206
# define BOOST_PP_SEQ_SIZE_206(_) BOOST_PP_SEQ_SIZE_207
# define BOOST_PP_SEQ_SIZE_207(_) BOOST_PP_SEQ_SIZE_208
# define BOOST_PP_SEQ_SIZE_208(_) BOOST_PP_SEQ_SIZE_209
# define BOOST_PP_SEQ_SIZE_209(_) BOOST_PP_SEQ_SIZE_210
# define BOOST_PP_SEQ_SIZE_210(_) BOOST_PP_SEQ_SIZE_211
# define BOOST_PP_SEQ_SIZE_211(_) BOOST_PP_SEQ_SIZE_212
# define BOOST_PP_SEQ_SIZE_212(_) BOOST_PP_SEQ_SIZE_213
# define BOOST_PP_SEQ_SIZE_213(_) BOOST_PP_SEQ_SIZE_214
# define BOOST_PP_SEQ_SIZE_214(_) BOOST_PP_SEQ_SIZE_215
# define BOOST_PP_SEQ_SIZE_215(_) BOOST_PP_SEQ_SIZE_216
# define BOOST_PP_SEQ_SIZE_216(_) BOOST_PP_SEQ_SIZE_217
# define BOOST_PP_SEQ_SIZE_217(_) BOOST_PP_SEQ_SIZE_218
# define BOOST_PP_SEQ_SIZE_218(_) BOOST_PP_SEQ_SIZE_219
# define BOOST_PP_SEQ_SIZE_219(_) BOOST_PP_SEQ_SIZE_220
# define BOOST_PP_SEQ_SIZE_220(_) BOOST_PP_SEQ_SIZE_221
# define BOOST_PP_SEQ_SIZE_221(_) BOOST_PP_SEQ_SIZE_222
# define BOOST_PP_SEQ_SIZE_222(_) BOOST_PP_SEQ_SIZE_223
# define BOOST_PP_SEQ_SIZE_223(_) BOOST_PP_SEQ_SIZE_224
# define BOOST_PP_SEQ_SIZE_224(_) BOOST_PP_SEQ_SIZE_225
# define BOOST_PP_SEQ_SIZE_225(_) BOOST_PP_SEQ_SIZE_226
# define BOOST_PP_SEQ_SIZE_226(_) BOOST_PP_SEQ_SIZE_227
# define BOOST_PP_SEQ_SIZE_227(_) BOOST_PP_SEQ_SIZE_228
# define BOOST_PP_SEQ_SIZE_228(_) BOOST_PP_SEQ_SIZE_229
# define BOOST_PP_SEQ_SIZE_229(_) BOOST_PP_SEQ_SIZE_230
# define BOOST_PP_SEQ_SIZE_230(_) BOOST_PP_SEQ_SIZE_231
# define BOOST_PP_SEQ_SIZE_231(_) BOOST_PP_SEQ_SIZE_232
# define BOOST_PP_SEQ_SIZE_232(_) BOOST_PP_SEQ_SIZE_233
# define BOOST_PP_SEQ_SIZE_233(_) BOOST_PP_SEQ_SIZE_234
# define BOOST_PP_SEQ_SIZE_234(_) BOOST_PP_SEQ_SIZE_235
# define BOOST_PP_SEQ_SIZE_235(_) BOOST_PP_SEQ_SIZE_236
# define BOOST_PP_SEQ_SIZE_236(_) BOOST_PP_SEQ_SIZE_237
# define BOOST_PP_SEQ_SIZE_237(_) BOOST_PP_SEQ_SIZE_238
# define BOOST_PP_SEQ_SIZE_238(_) BOOST_PP_SEQ_SIZE_239
# define BOOST_PP_SEQ_SIZE_239(_) BOOST_PP_SEQ_SIZE_240
# define BOOST_PP_SEQ_SIZE_240(_) BOOST_PP_SEQ_SIZE_241
# define BOOST_PP_SEQ_SIZE_241(_) BOOST_PP_SEQ_SIZE_242
# define BOOST_PP_SEQ_SIZE_242(_) BOOST_PP_SEQ_SIZE_243
# define BOOST_PP_SEQ_SIZE_243(_) BOOST_PP_SEQ_SIZE_244
# define BOOST_PP_SEQ_SIZE_244(_) BOOST_PP_SEQ_SIZE_245
# define BOOST_PP_SEQ_SIZE_245(_) BOOST_PP_SEQ_SIZE_246
# define BOOST_PP_SEQ_SIZE_246(_) BOOST_PP_SEQ_SIZE_247
# define BOOST_PP_SEQ_SIZE_247(_) BOOST_PP_SEQ_SIZE_248
# define BOOST_PP_SEQ_SIZE_248(_) BOOST_PP_SEQ_SIZE_249
# define BOOST_PP_SEQ_SIZE_249(_) BOOST_PP_SEQ_SIZE_250
# define BOOST_PP_SEQ_SIZE_250(_) BOOST_PP_SEQ_SIZE_251
# define BOOST_PP_SEQ_SIZE_251(_) BOOST_PP_SEQ_SIZE_252
# define BOOST_PP_SEQ_SIZE_252(_) BOOST_PP_SEQ_SIZE_253
# define BOOST_PP_SEQ_SIZE_253(_) BOOST_PP_SEQ_SIZE_254
# define BOOST_PP_SEQ_SIZE_254(_) BOOST_PP_SEQ_SIZE_255
# define BOOST_PP_SEQ_SIZE_255(_) BOOST_PP_SEQ_SIZE_256
# define BOOST_PP_SEQ_SIZE_256(_) BOOST_PP_SEQ_SIZE_257
#
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_0 0
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_1 1
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_2 2
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_3 3
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_4 4
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_5 5
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_6 6
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_7 7
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_8 8
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_9 9
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_10 10
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_11 11
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_12 12
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_13 13
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_14 14
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_15 15
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_16 16
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_17 17
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_18 18
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_19 19
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_20 20
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_21 21
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_22 22
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_23 23
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_24 24
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_25 25
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_26 26
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_27 27
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_28 28
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_29 29
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_30 30
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_31 31
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_32 32
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_33 33
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_34 34
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_35 35
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_36 36
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_37 37
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_38 38
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_39 39
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_40 40
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_41 41
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_42 42
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_43 43
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_44 44
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_45 45
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_46 46
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_47 47
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_48 48
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_49 49
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_50 50
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_51 51
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_52 52
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_53 53
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_54 54
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_55 55
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_56 56
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_57 57
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_58 58
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_59 59
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_60 60
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_61 61
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_62 62
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_63 63
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_64 64
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_65 65
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_66 66
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_67 67
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_68 68
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_69 69
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_70 70
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_71 71
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_72 72
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_73 73
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_74 74
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_75 75
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_76 76
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_77 77
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_78 78
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_79 79
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_80 80
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_81 81
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_82 82
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_83 83
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_84 84
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_85 85
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_86 86
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_87 87
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_88 88
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_89 89
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_90 90
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_91 91
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_92 92
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_93 93
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_94 94
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_95 95
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_96 96
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_97 97
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_98 98
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_99 99
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_100 100
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_101 101
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_102 102
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_103 103
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_104 104
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_105 105
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_106 106
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_107 107
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_108 108
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_109 109
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_110 110
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_111 111
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_112 112
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_113 113
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_114 114
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_115 115
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_116 116
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_117 117
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_118 118
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_119 119
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_120 120
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_121 121
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_122 122
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_123 123
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_124 124
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_125 125
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_126 126
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_127 127
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_128 128
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_129 129
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_130 130
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_131 131
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_132 132
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_133 133
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_134 134
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_135 135
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_136 136
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_137 137
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_138 138
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_139 139
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_140 140
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_141 141
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_142 142
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_143 143
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_144 144
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_145 145
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_146 146
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_147 147
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_148 148
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_149 149
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_150 150
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_151 151
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_152 152
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_153 153
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_154 154
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_155 155
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_156 156
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_157 157
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_158 158
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_159 159
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_160 160
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_161 161
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_162 162
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_163 163
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_164 164
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_165 165
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_166 166
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_167 167
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_168 168
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_169 169
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_170 170
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_171 171
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_172 172
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_173 173
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_174 174
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_175 175
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_176 176
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_177 177
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_178 178
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_179 179
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_180 180
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_181 181
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_182 182
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_183 183
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_184 184
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_185 185
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_186 186
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_187 187
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_188 188
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_189 189
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_190 190
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_191 191
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_192 192
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_193 193
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_194 194
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_195 195
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_196 196
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_197 197
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_198 198
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_199 199
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_200 200
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_201 201
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_202 202
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_203 203
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_204 204
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_205 205
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_206 206
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_207 207
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_208 208
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_209 209
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_210 210
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_211 211
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_212 212
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_213 213
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_214 214
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_215 215
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_216 216
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_217 217
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_218 218
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_219 219
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_220 220
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_221 221
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_222 222
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_223 223
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_224 224
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_225 225
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_226 226
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_227 227
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_228 228
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_229 229
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_230 230
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_231 231
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_232 232
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_233 233
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_234 234
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_235 235
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_236 236
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_237 237
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_238 238
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_239 239
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_240 240
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_241 241
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_242 242
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_243 243
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_244 244
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_245 245
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_246 246
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_247 247
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_248 248
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_249 249
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_250 250
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_251 251
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_252 252
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_253 253
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_254 254
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_255 255
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_256 256
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_257 257
#
# else
#
# include <boost_kahypar/preprocessor/config/limits.hpp>
#
# if BOOST_PP_LIMIT_SEQ == 256
# include <boost_kahypar/preprocessor/seq/limits/size_256.hpp>
# elif BOOST_PP_LIMIT_SEQ == 512
# include <boost_kahypar/preprocessor/seq/limits/size_256.hpp>
# include <boost_kahypar/preprocessor/seq/limits/size_512.hpp>
# elif BOOST_PP_LIMIT_SEQ == 1024
# include <boost_kahypar/preprocessor/seq/limits/size_256.hpp>
# include <boost_kahypar/preprocessor/seq/limits/size_512.hpp>
# include <boost_kahypar/preprocessor/seq/limits/size_1024.hpp>
# else
# error Incorrect value for the BOOST_PP_LIMIT_SEQ limit
# endif
#
# endif
#
# endif
