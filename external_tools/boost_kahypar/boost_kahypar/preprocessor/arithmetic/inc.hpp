# /* Copyright (C) 2001
#  * Housemarque Oy
#  * http://www.housemarque.com
#  *
#  * Distributed under the Boost Software License, Version 1.0. (See
#  * accompanying file LICENSE_1_0.txt or copy at
#  * http://www.boost.org/LICENSE_1_0.txt)
#  */
#
# /* Revised by Paul Mensonides (2002) */
# /* Revised by Edward Diener (2020) */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef BOOST_PREPROCESSOR_ARITHMETIC_INC_HPP
# define BOOST_PREPROCESSOR_ARITHMETIC_INC_HPP
#
# include <boost_kahypar/preprocessor/config/config.hpp>
#
# if ~BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_STRICT()
#
# /* BOOST_PP_INC */
#
# if ~BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_MWCC()
#    define BOOST_PP_INC(x) BOOST_PP_INC_I(x)
# else
#    define BOOST_PP_INC(x) BOOST_PP_INC_OO((x))
#    define BOOST_PP_INC_OO(par) BOOST_PP_INC_I ## par
# endif
#
# define BOOST_PP_INC_I(x) BOOST_PP_INC_ ## x
#
# define BOOST_PP_INC_0 1
# define BOOST_PP_INC_1 2
# define BOOST_PP_INC_2 3
# define BOOST_PP_INC_3 4
# define BOOST_PP_INC_4 5
# define BOOST_PP_INC_5 6
# define BOOST_PP_INC_6 7
# define BOOST_PP_INC_7 8
# define BOOST_PP_INC_8 9
# define BOOST_PP_INC_9 10
# define BOOST_PP_INC_10 11
# define BOOST_PP_INC_11 12
# define BOOST_PP_INC_12 13
# define BOOST_PP_INC_13 14
# define BOOST_PP_INC_14 15
# define BOOST_PP_INC_15 16
# define BOOST_PP_INC_16 17
# define BOOST_PP_INC_17 18
# define BOOST_PP_INC_18 19
# define BOOST_PP_INC_19 20
# define BOOST_PP_INC_20 21
# define BOOST_PP_INC_21 22
# define BOOST_PP_INC_22 23
# define BOOST_PP_INC_23 24
# define BOOST_PP_INC_24 25
# define BOOST_PP_INC_25 26
# define BOOST_PP_INC_26 27
# define BOOST_PP_INC_27 28
# define BOOST_PP_INC_28 29
# define BOOST_PP_INC_29 30
# define BOOST_PP_INC_30 31
# define BOOST_PP_INC_31 32
# define BOOST_PP_INC_32 33
# define BOOST_PP_INC_33 34
# define BOOST_PP_INC_34 35
# define BOOST_PP_INC_35 36
# define BOOST_PP_INC_36 37
# define BOOST_PP_INC_37 38
# define BOOST_PP_INC_38 39
# define BOOST_PP_INC_39 40
# define BOOST_PP_INC_40 41
# define BOOST_PP_INC_41 42
# define BOOST_PP_INC_42 43
# define BOOST_PP_INC_43 44
# define BOOST_PP_INC_44 45
# define BOOST_PP_INC_45 46
# define BOOST_PP_INC_46 47
# define BOOST_PP_INC_47 48
# define BOOST_PP_INC_48 49
# define BOOST_PP_INC_49 50
# define BOOST_PP_INC_50 51
# define BOOST_PP_INC_51 52
# define BOOST_PP_INC_52 53
# define BOOST_PP_INC_53 54
# define BOOST_PP_INC_54 55
# define BOOST_PP_INC_55 56
# define BOOST_PP_INC_56 57
# define BOOST_PP_INC_57 58
# define BOOST_PP_INC_58 59
# define BOOST_PP_INC_59 60
# define BOOST_PP_INC_60 61
# define BOOST_PP_INC_61 62
# define BOOST_PP_INC_62 63
# define BOOST_PP_INC_63 64
# define BOOST_PP_INC_64 65
# define BOOST_PP_INC_65 66
# define BOOST_PP_INC_66 67
# define BOOST_PP_INC_67 68
# define BOOST_PP_INC_68 69
# define BOOST_PP_INC_69 70
# define BOOST_PP_INC_70 71
# define BOOST_PP_INC_71 72
# define BOOST_PP_INC_72 73
# define BOOST_PP_INC_73 74
# define BOOST_PP_INC_74 75
# define BOOST_PP_INC_75 76
# define BOOST_PP_INC_76 77
# define BOOST_PP_INC_77 78
# define BOOST_PP_INC_78 79
# define BOOST_PP_INC_79 80
# define BOOST_PP_INC_80 81
# define BOOST_PP_INC_81 82
# define BOOST_PP_INC_82 83
# define BOOST_PP_INC_83 84
# define BOOST_PP_INC_84 85
# define BOOST_PP_INC_85 86
# define BOOST_PP_INC_86 87
# define BOOST_PP_INC_87 88
# define BOOST_PP_INC_88 89
# define BOOST_PP_INC_89 90
# define BOOST_PP_INC_90 91
# define BOOST_PP_INC_91 92
# define BOOST_PP_INC_92 93
# define BOOST_PP_INC_93 94
# define BOOST_PP_INC_94 95
# define BOOST_PP_INC_95 96
# define BOOST_PP_INC_96 97
# define BOOST_PP_INC_97 98
# define BOOST_PP_INC_98 99
# define BOOST_PP_INC_99 100
# define BOOST_PP_INC_100 101
# define BOOST_PP_INC_101 102
# define BOOST_PP_INC_102 103
# define BOOST_PP_INC_103 104
# define BOOST_PP_INC_104 105
# define BOOST_PP_INC_105 106
# define BOOST_PP_INC_106 107
# define BOOST_PP_INC_107 108
# define BOOST_PP_INC_108 109
# define BOOST_PP_INC_109 110
# define BOOST_PP_INC_110 111
# define BOOST_PP_INC_111 112
# define BOOST_PP_INC_112 113
# define BOOST_PP_INC_113 114
# define BOOST_PP_INC_114 115
# define BOOST_PP_INC_115 116
# define BOOST_PP_INC_116 117
# define BOOST_PP_INC_117 118
# define BOOST_PP_INC_118 119
# define BOOST_PP_INC_119 120
# define BOOST_PP_INC_120 121
# define BOOST_PP_INC_121 122
# define BOOST_PP_INC_122 123
# define BOOST_PP_INC_123 124
# define BOOST_PP_INC_124 125
# define BOOST_PP_INC_125 126
# define BOOST_PP_INC_126 127
# define BOOST_PP_INC_127 128
# define BOOST_PP_INC_128 129
# define BOOST_PP_INC_129 130
# define BOOST_PP_INC_130 131
# define BOOST_PP_INC_131 132
# define BOOST_PP_INC_132 133
# define BOOST_PP_INC_133 134
# define BOOST_PP_INC_134 135
# define BOOST_PP_INC_135 136
# define BOOST_PP_INC_136 137
# define BOOST_PP_INC_137 138
# define BOOST_PP_INC_138 139
# define BOOST_PP_INC_139 140
# define BOOST_PP_INC_140 141
# define BOOST_PP_INC_141 142
# define BOOST_PP_INC_142 143
# define BOOST_PP_INC_143 144
# define BOOST_PP_INC_144 145
# define BOOST_PP_INC_145 146
# define BOOST_PP_INC_146 147
# define BOOST_PP_INC_147 148
# define BOOST_PP_INC_148 149
# define BOOST_PP_INC_149 150
# define BOOST_PP_INC_150 151
# define BOOST_PP_INC_151 152
# define BOOST_PP_INC_152 153
# define BOOST_PP_INC_153 154
# define BOOST_PP_INC_154 155
# define BOOST_PP_INC_155 156
# define BOOST_PP_INC_156 157
# define BOOST_PP_INC_157 158
# define BOOST_PP_INC_158 159
# define BOOST_PP_INC_159 160
# define BOOST_PP_INC_160 161
# define BOOST_PP_INC_161 162
# define BOOST_PP_INC_162 163
# define BOOST_PP_INC_163 164
# define BOOST_PP_INC_164 165
# define BOOST_PP_INC_165 166
# define BOOST_PP_INC_166 167
# define BOOST_PP_INC_167 168
# define BOOST_PP_INC_168 169
# define BOOST_PP_INC_169 170
# define BOOST_PP_INC_170 171
# define BOOST_PP_INC_171 172
# define BOOST_PP_INC_172 173
# define BOOST_PP_INC_173 174
# define BOOST_PP_INC_174 175
# define BOOST_PP_INC_175 176
# define BOOST_PP_INC_176 177
# define BOOST_PP_INC_177 178
# define BOOST_PP_INC_178 179
# define BOOST_PP_INC_179 180
# define BOOST_PP_INC_180 181
# define BOOST_PP_INC_181 182
# define BOOST_PP_INC_182 183
# define BOOST_PP_INC_183 184
# define BOOST_PP_INC_184 185
# define BOOST_PP_INC_185 186
# define BOOST_PP_INC_186 187
# define BOOST_PP_INC_187 188
# define BOOST_PP_INC_188 189
# define BOOST_PP_INC_189 190
# define BOOST_PP_INC_190 191
# define BOOST_PP_INC_191 192
# define BOOST_PP_INC_192 193
# define BOOST_PP_INC_193 194
# define BOOST_PP_INC_194 195
# define BOOST_PP_INC_195 196
# define BOOST_PP_INC_196 197
# define BOOST_PP_INC_197 198
# define BOOST_PP_INC_198 199
# define BOOST_PP_INC_199 200
# define BOOST_PP_INC_200 201
# define BOOST_PP_INC_201 202
# define BOOST_PP_INC_202 203
# define BOOST_PP_INC_203 204
# define BOOST_PP_INC_204 205
# define BOOST_PP_INC_205 206
# define BOOST_PP_INC_206 207
# define BOOST_PP_INC_207 208
# define BOOST_PP_INC_208 209
# define BOOST_PP_INC_209 210
# define BOOST_PP_INC_210 211
# define BOOST_PP_INC_211 212
# define BOOST_PP_INC_212 213
# define BOOST_PP_INC_213 214
# define BOOST_PP_INC_214 215
# define BOOST_PP_INC_215 216
# define BOOST_PP_INC_216 217
# define BOOST_PP_INC_217 218
# define BOOST_PP_INC_218 219
# define BOOST_PP_INC_219 220
# define BOOST_PP_INC_220 221
# define BOOST_PP_INC_221 222
# define BOOST_PP_INC_222 223
# define BOOST_PP_INC_223 224
# define BOOST_PP_INC_224 225
# define BOOST_PP_INC_225 226
# define BOOST_PP_INC_226 227
# define BOOST_PP_INC_227 228
# define BOOST_PP_INC_228 229
# define BOOST_PP_INC_229 230
# define BOOST_PP_INC_230 231
# define BOOST_PP_INC_231 232
# define BOOST_PP_INC_232 233
# define BOOST_PP_INC_233 234
# define BOOST_PP_INC_234 235
# define BOOST_PP_INC_235 236
# define BOOST_PP_INC_236 237
# define BOOST_PP_INC_237 238
# define BOOST_PP_INC_238 239
# define BOOST_PP_INC_239 240
# define BOOST_PP_INC_240 241
# define BOOST_PP_INC_241 242
# define BOOST_PP_INC_242 243
# define BOOST_PP_INC_243 244
# define BOOST_PP_INC_244 245
# define BOOST_PP_INC_245 246
# define BOOST_PP_INC_246 247
# define BOOST_PP_INC_247 248
# define BOOST_PP_INC_248 249
# define BOOST_PP_INC_249 250
# define BOOST_PP_INC_250 251
# define BOOST_PP_INC_251 252
# define BOOST_PP_INC_252 253
# define BOOST_PP_INC_253 254
# define BOOST_PP_INC_254 255
# define BOOST_PP_INC_255 256
# define BOOST_PP_INC_256 256
#
# else
#
# /* BOOST_PP_INC */
#
# if ~BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_MWCC()
#    define BOOST_PP_INC(x) BOOST_PP_INC_I(x)
# else
#    define BOOST_PP_INC(x) BOOST_PP_INC_OO((x))
#    define BOOST_PP_INC_OO(par) BOOST_PP_INC_I ## par
# endif
#
# define BOOST_PP_INC_I(x) BOOST_PP_INC_ ## x
#
# include <boost_kahypar/preprocessor/config/limits.hpp>
#
# if BOOST_PP_LIMIT_MAG == 256
# include <boost_kahypar/preprocessor/arithmetic/limits/inc_256.hpp>
# elif BOOST_PP_LIMIT_MAG == 512
# include <boost_kahypar/preprocessor/arithmetic/limits/inc_256.hpp>
# include <boost_kahypar/preprocessor/arithmetic/limits/inc_512.hpp>
# elif BOOST_PP_LIMIT_MAG == 1024
# include <boost_kahypar/preprocessor/arithmetic/limits/inc_256.hpp>
# include <boost_kahypar/preprocessor/arithmetic/limits/inc_512.hpp>
# include <boost_kahypar/preprocessor/arithmetic/limits/inc_1024.hpp>
# else
# error Incorrect value for the BOOST_PP_LIMIT_MAG limit
# endif
#
# endif
#
# endif
