INCLUDEPATH += $$PWD/.

HEADERS += \
    $$PWD/Catch2/include/catch.hpp \
    $$PWD/Catch2/include/catch_with_main.hpp \
    $$PWD/Catch2/include/external/clara.hpp \
    $$PWD/Catch2/include/internal/benchmark/catch_benchmark.hpp \
    $$PWD/Catch2/include/internal/benchmark/catch_chronometer.hpp \
    $$PWD/Catch2/include/internal/benchmark/catch_clock.hpp \
    $$PWD/Catch2/include/internal/benchmark/catch_constructor.hpp \
    $$PWD/Catch2/include/internal/benchmark/catch_environment.hpp \
    $$PWD/Catch2/include/internal/benchmark/catch_estimate.hpp \
    $$PWD/Catch2/include/internal/benchmark/catch_execution_plan.hpp \
    $$PWD/Catch2/include/internal/benchmark/catch_optimizer.hpp \
    $$PWD/Catch2/include/internal/benchmark/catch_outlier_classification.hpp \
    $$PWD/Catch2/include/internal/benchmark/catch_sample_analysis.hpp \
    $$PWD/Catch2/include/internal/benchmark/detail/catch_analyse.hpp \
    $$PWD/Catch2/include/internal/benchmark/detail/catch_benchmark_function.hpp \
    $$PWD/Catch2/include/internal/benchmark/detail/catch_complete_invoke.hpp \
    $$PWD/Catch2/include/internal/benchmark/detail/catch_estimate_clock.hpp \
    $$PWD/Catch2/include/internal/benchmark/detail/catch_measure.hpp \
    $$PWD/Catch2/include/internal/benchmark/detail/catch_repeat.hpp \
    $$PWD/Catch2/include/internal/benchmark/detail/catch_run_for_at_least.hpp \
    $$PWD/Catch2/include/internal/benchmark/detail/catch_stats.hpp \
    $$PWD/Catch2/include/internal/benchmark/detail/catch_timing.hpp \
    $$PWD/Catch2/include/internal/catch_approx.h \
    $$PWD/Catch2/include/internal/catch_assertionhandler.h \
    $$PWD/Catch2/include/internal/catch_assertioninfo.h \
    $$PWD/Catch2/include/internal/catch_assertionresult.h \
    $$PWD/Catch2/include/internal/catch_capture.hpp \
    $$PWD/Catch2/include/internal/catch_capture_matchers.h \
    $$PWD/Catch2/include/internal/catch_clara.h \
    $$PWD/Catch2/include/internal/catch_commandline.h \
    $$PWD/Catch2/include/internal/catch_common.h \
    $$PWD/Catch2/include/internal/catch_compiler_capabilities.h \
    $$PWD/Catch2/include/internal/catch_config.hpp \
    $$PWD/Catch2/include/internal/catch_console_colour.h \
    $$PWD/Catch2/include/internal/catch_context.h \
    $$PWD/Catch2/include/internal/catch_debug_console.h \
    $$PWD/Catch2/include/internal/catch_debugger.h \
    $$PWD/Catch2/include/internal/catch_decomposer.h \
    $$PWD/Catch2/include/internal/catch_default_main.hpp \
    $$PWD/Catch2/include/internal/catch_enforce.h \
    $$PWD/Catch2/include/internal/catch_enum_values_registry.h \
    $$PWD/Catch2/include/internal/catch_errno_guard.h \
    $$PWD/Catch2/include/internal/catch_exception_translator_registry.h \
    $$PWD/Catch2/include/internal/catch_external_interfaces.h \
    $$PWD/Catch2/include/internal/catch_fatal_condition.h \
    $$PWD/Catch2/include/internal/catch_generators.hpp \
    $$PWD/Catch2/include/internal/catch_generators_generic.hpp \
    $$PWD/Catch2/include/internal/catch_generators_specific.hpp \
    $$PWD/Catch2/include/internal/catch_impl.hpp \
    $$PWD/Catch2/include/internal/catch_interfaces_capture.h \
    $$PWD/Catch2/include/internal/catch_interfaces_config.h \
    $$PWD/Catch2/include/internal/catch_interfaces_enum_values_registry.h \
    $$PWD/Catch2/include/internal/catch_interfaces_exception.h \
    $$PWD/Catch2/include/internal/catch_interfaces_generatortracker.h \
    $$PWD/Catch2/include/internal/catch_interfaces_registry_hub.h \
    $$PWD/Catch2/include/internal/catch_interfaces_reporter.h \
    $$PWD/Catch2/include/internal/catch_interfaces_runner.h \
    $$PWD/Catch2/include/internal/catch_interfaces_tag_alias_registry.h \
    $$PWD/Catch2/include/internal/catch_interfaces_testcase.h \
    $$PWD/Catch2/include/internal/catch_leak_detector.h \
    $$PWD/Catch2/include/internal/catch_list.h \
    $$PWD/Catch2/include/internal/catch_matchers.h \
    $$PWD/Catch2/include/internal/catch_matchers_floating.h \
    $$PWD/Catch2/include/internal/catch_matchers_generic.hpp \
    $$PWD/Catch2/include/internal/catch_matchers_string.h \
    $$PWD/Catch2/include/internal/catch_matchers_vector.h \
    $$PWD/Catch2/include/internal/catch_message.h \
    $$PWD/Catch2/include/internal/catch_meta.hpp \
    $$PWD/Catch2/include/internal/catch_objc.hpp \
    $$PWD/Catch2/include/internal/catch_objc_arc.hpp \
    $$PWD/Catch2/include/internal/catch_option.hpp \
    $$PWD/Catch2/include/internal/catch_output_redirect.h \
    $$PWD/Catch2/include/internal/catch_platform.h \
    $$PWD/Catch2/include/internal/catch_polyfills.hpp \
    $$PWD/Catch2/include/internal/catch_preprocessor.hpp \
    $$PWD/Catch2/include/internal/catch_random_number_generator.h \
    $$PWD/Catch2/include/internal/catch_reenable_warnings.h \
    $$PWD/Catch2/include/internal/catch_reporter_registrars.hpp \
    $$PWD/Catch2/include/internal/catch_reporter_registry.h \
    $$PWD/Catch2/include/internal/catch_result_type.h \
    $$PWD/Catch2/include/internal/catch_run_context.h \
    $$PWD/Catch2/include/internal/catch_section.h \
    $$PWD/Catch2/include/internal/catch_section_info.h \
    $$PWD/Catch2/include/internal/catch_session.h \
    $$PWD/Catch2/include/internal/catch_singletons.hpp \
    $$PWD/Catch2/include/internal/catch_startup_exception_registry.h \
    $$PWD/Catch2/include/internal/catch_stream.h \
    $$PWD/Catch2/include/internal/catch_string_manip.h \
    $$PWD/Catch2/include/internal/catch_stringref.h \
    $$PWD/Catch2/include/internal/catch_suppress_warnings.h \
    $$PWD/Catch2/include/internal/catch_tag_alias.h \
    $$PWD/Catch2/include/internal/catch_tag_alias_autoregistrar.h \
    $$PWD/Catch2/include/internal/catch_tag_alias_registry.h \
    $$PWD/Catch2/include/internal/catch_test_case_info.h \
    $$PWD/Catch2/include/internal/catch_test_case_registry_impl.h \
    $$PWD/Catch2/include/internal/catch_test_case_tracker.h \
    $$PWD/Catch2/include/internal/catch_test_registry.h \
    $$PWD/Catch2/include/internal/catch_test_spec.h \
    $$PWD/Catch2/include/internal/catch_test_spec_parser.h \
    $$PWD/Catch2/include/internal/catch_text.h \
    $$PWD/Catch2/include/internal/catch_timer.h \
    $$PWD/Catch2/include/internal/catch_to_string.hpp \
    $$PWD/Catch2/include/internal/catch_tostring.h \
    $$PWD/Catch2/include/internal/catch_totals.h \
    $$PWD/Catch2/include/internal/catch_type_traits.hpp \
    $$PWD/Catch2/include/internal/catch_uncaught_exceptions.h \
    $$PWD/Catch2/include/internal/catch_user_interfaces.h \
    $$PWD/Catch2/include/internal/catch_version.h \
    $$PWD/Catch2/include/internal/catch_wildcard_pattern.h \
    $$PWD/Catch2/include/internal/catch_windows_h_proxy.h \
    $$PWD/Catch2/include/internal/catch_xmlwriter.h \
    $$PWD/Catch2/include/reporters/catch_reporter_automake.hpp \
    $$PWD/Catch2/include/reporters/catch_reporter_bases.hpp \
    $$PWD/Catch2/include/reporters/catch_reporter_compact.h \
    $$PWD/Catch2/include/reporters/catch_reporter_console.h \
    $$PWD/Catch2/include/reporters/catch_reporter_junit.h \
    $$PWD/Catch2/include/reporters/catch_reporter_listening.h \
    $$PWD/Catch2/include/reporters/catch_reporter_tap.hpp \
    $$PWD/Catch2/include/reporters/catch_reporter_teamcity.hpp \
    $$PWD/Catch2/include/reporters/catch_reporter_xml.h \
    $$PWD/Catch2/projects/XCode/OCTest/OCTest/CatchOCTestCase.h \
    $$PWD/Catch2/projects/XCode/OCTest/OCTest/TestObj.h \
    $$PWD/Catch2/single_include/catch2/catch.hpp \
    $$PWD/Catch2/single_include/catch2/catch_reporter_automake.hpp \
    $$PWD/Catch2/single_include/catch2/catch_reporter_tap.hpp \
    $$PWD/Catch2/single_include/catch2/catch_reporter_teamcity.hpp \
    $$PWD/Catch2/third_party/clara.hpp

SOURCES += \
    $$PWD/Catch2/include/internal/benchmark/detail/catch_stats.cpp \
    $$PWD/Catch2/include/internal/catch_approx.cpp \
    $$PWD/Catch2/include/internal/catch_assertionhandler.cpp \
    $$PWD/Catch2/include/internal/catch_assertionresult.cpp \
    $$PWD/Catch2/include/internal/catch_capture_matchers.cpp \
    $$PWD/Catch2/include/internal/catch_commandline.cpp \
    $$PWD/Catch2/include/internal/catch_common.cpp \
    $$PWD/Catch2/include/internal/catch_config.cpp \
    $$PWD/Catch2/include/internal/catch_console_colour.cpp \
    $$PWD/Catch2/include/internal/catch_context.cpp \
    $$PWD/Catch2/include/internal/catch_debug_console.cpp \
    $$PWD/Catch2/include/internal/catch_debugger.cpp \
    $$PWD/Catch2/include/internal/catch_decomposer.cpp \
    $$PWD/Catch2/include/internal/catch_enforce.cpp \
    $$PWD/Catch2/include/internal/catch_enum_values_registry.cpp \
    $$PWD/Catch2/include/internal/catch_errno_guard.cpp \
    $$PWD/Catch2/include/internal/catch_exception_translator_registry.cpp \
    $$PWD/Catch2/include/internal/catch_fatal_condition.cpp \
    $$PWD/Catch2/include/internal/catch_generators.cpp \
    $$PWD/Catch2/include/internal/catch_interfaces_capture.cpp \
    $$PWD/Catch2/include/internal/catch_interfaces_config.cpp \
    $$PWD/Catch2/include/internal/catch_interfaces_exception.cpp \
    $$PWD/Catch2/include/internal/catch_interfaces_registry_hub.cpp \
    $$PWD/Catch2/include/internal/catch_interfaces_reporter.cpp \
    $$PWD/Catch2/include/internal/catch_interfaces_runner.cpp \
    $$PWD/Catch2/include/internal/catch_interfaces_testcase.cpp \
    $$PWD/Catch2/include/internal/catch_leak_detector.cpp \
    $$PWD/Catch2/include/internal/catch_list.cpp \
    $$PWD/Catch2/include/internal/catch_matchers.cpp \
    $$PWD/Catch2/include/internal/catch_matchers_floating.cpp \
    $$PWD/Catch2/include/internal/catch_matchers_generic.cpp \
    $$PWD/Catch2/include/internal/catch_matchers_string.cpp \
    $$PWD/Catch2/include/internal/catch_message.cpp \
    $$PWD/Catch2/include/internal/catch_output_redirect.cpp \
    $$PWD/Catch2/include/internal/catch_polyfills.cpp \
    $$PWD/Catch2/include/internal/catch_random_number_generator.cpp \
    $$PWD/Catch2/include/internal/catch_registry_hub.cpp \
    $$PWD/Catch2/include/internal/catch_reporter_registry.cpp \
    $$PWD/Catch2/include/internal/catch_result_type.cpp \
    $$PWD/Catch2/include/internal/catch_run_context.cpp \
    $$PWD/Catch2/include/internal/catch_section.cpp \
    $$PWD/Catch2/include/internal/catch_section_info.cpp \
    $$PWD/Catch2/include/internal/catch_session.cpp \
    $$PWD/Catch2/include/internal/catch_singletons.cpp \
    $$PWD/Catch2/include/internal/catch_startup_exception_registry.cpp \
    $$PWD/Catch2/include/internal/catch_stream.cpp \
    $$PWD/Catch2/include/internal/catch_string_manip.cpp \
    $$PWD/Catch2/include/internal/catch_stringref.cpp \
    $$PWD/Catch2/include/internal/catch_tag_alias.cpp \
    $$PWD/Catch2/include/internal/catch_tag_alias_autoregistrar.cpp \
    $$PWD/Catch2/include/internal/catch_tag_alias_registry.cpp \
    $$PWD/Catch2/include/internal/catch_test_case_info.cpp \
    $$PWD/Catch2/include/internal/catch_test_case_registry_impl.cpp \
    $$PWD/Catch2/include/internal/catch_test_case_tracker.cpp \
    $$PWD/Catch2/include/internal/catch_test_registry.cpp \
    $$PWD/Catch2/include/internal/catch_test_spec.cpp \
    $$PWD/Catch2/include/internal/catch_test_spec_parser.cpp \
    $$PWD/Catch2/include/internal/catch_timer.cpp \
    $$PWD/Catch2/include/internal/catch_tostring.cpp \
    $$PWD/Catch2/include/internal/catch_totals.cpp \
    $$PWD/Catch2/include/internal/catch_uncaught_exceptions.cpp \
    $$PWD/Catch2/include/internal/catch_version.cpp \
    $$PWD/Catch2/include/internal/catch_wildcard_pattern.cpp \
    $$PWD/Catch2/include/internal/catch_xmlwriter.cpp \
    $$PWD/Catch2/include/reporters/catch_reporter_bases.cpp \
    $$PWD/Catch2/include/reporters/catch_reporter_compact.cpp \
    $$PWD/Catch2/include/reporters/catch_reporter_console.cpp \
    $$PWD/Catch2/include/reporters/catch_reporter_junit.cpp \
    $$PWD/Catch2/include/reporters/catch_reporter_listening.cpp \
    $$PWD/Catch2/include/reporters/catch_reporter_xml.cpp \
#    Catch2/misc/coverage-helper.cpp \
#    Catch2/projects/ExtraTests/X01-PrefixedMacros.cpp \
#    Catch2/projects/ExtraTests/X02-DisabledMacros.cpp \
#    Catch2/projects/ExtraTests/X03-DisabledExceptions-DefaultHandler.cpp \
#    Catch2/projects/ExtraTests/X04-DisabledExceptions-CustomHandler.cpp \
#    Catch2/projects/ExtraTests/X10-FallbackStringifier.cpp \
#    Catch2/projects/ExtraTests/X11-DisableStringification.cpp \
#    Catch2/projects/ExtraTests/X20-BenchmarkingMacros.cpp \
#    Catch2/projects/SelfTest/CompileTimePerfTests/10.tests.cpp \
#    Catch2/projects/SelfTest/CompileTimePerfTests/100.tests.cpp \
#    Catch2/projects/SelfTest/CompileTimePerfTests/All.tests.cpp \
#    Catch2/projects/SelfTest/IntrospectiveTests/CmdLine.tests.cpp \
#    Catch2/projects/SelfTest/IntrospectiveTests/GeneratorsImpl.tests.cpp \
#    Catch2/projects/SelfTest/IntrospectiveTests/InternalBenchmark.tests.cpp \
#    Catch2/projects/SelfTest/IntrospectiveTests/PartTracker.tests.cpp \
#    Catch2/projects/SelfTest/IntrospectiveTests/String.tests.cpp \
#    Catch2/projects/SelfTest/IntrospectiveTests/Tag.tests.cpp \
#    Catch2/projects/SelfTest/IntrospectiveTests/ToString.tests.cpp \
#    Catch2/projects/SelfTest/IntrospectiveTests/Xml.tests.cpp \
#    Catch2/projects/SelfTest/SurrogateCpps/catch_console_colour.cpp \
#    Catch2/projects/SelfTest/SurrogateCpps/catch_debugger.cpp \
#    Catch2/projects/SelfTest/SurrogateCpps/catch_interfaces_reporter.cpp \
#    Catch2/projects/SelfTest/SurrogateCpps/catch_option.cpp \
#    Catch2/projects/SelfTest/SurrogateCpps/catch_stream.cpp \
#    Catch2/projects/SelfTest/SurrogateCpps/catch_test_case_tracker.cpp \
#    Catch2/projects/SelfTest/SurrogateCpps/catch_test_spec.cpp \
#    Catch2/projects/SelfTest/SurrogateCpps/catch_xmlwriter.cpp \
#    Catch2/projects/SelfTest/TestMain.cpp \
#    Catch2/projects/SelfTest/UsageTests/Approx.tests.cpp \
#    Catch2/projects/SelfTest/UsageTests/BDD.tests.cpp \
#    Catch2/projects/SelfTest/UsageTests/Benchmark.tests.cpp \
#    Catch2/projects/SelfTest/UsageTests/Class.tests.cpp \
#    Catch2/projects/SelfTest/UsageTests/Compilation.tests.cpp \
#    Catch2/projects/SelfTest/UsageTests/Condition.tests.cpp \
#    Catch2/projects/SelfTest/UsageTests/Decomposition.tests.cpp \
#    Catch2/projects/SelfTest/UsageTests/EnumToString.tests.cpp \
#    Catch2/projects/SelfTest/UsageTests/Exception.tests.cpp \
#    Catch2/projects/SelfTest/UsageTests/Generators.tests.cpp \
#    Catch2/projects/SelfTest/UsageTests/Matchers.tests.cpp \
#    Catch2/projects/SelfTest/UsageTests/Message.tests.cpp \
#    Catch2/projects/SelfTest/UsageTests/Misc.tests.cpp \
#    Catch2/projects/SelfTest/UsageTests/ToStringByte.tests.cpp \
#    Catch2/projects/SelfTest/UsageTests/ToStringChrono.tests.cpp \
#    Catch2/projects/SelfTest/UsageTests/ToStringGeneral.tests.cpp \
#    Catch2/projects/SelfTest/UsageTests/ToStringOptional.tests.cpp \
#    Catch2/projects/SelfTest/UsageTests/ToStringPair.tests.cpp \
#    Catch2/projects/SelfTest/UsageTests/ToStringTuple.tests.cpp \
#    Catch2/projects/SelfTest/UsageTests/ToStringVariant.tests.cpp \
#    Catch2/projects/SelfTest/UsageTests/ToStringVector.tests.cpp \
#    Catch2/projects/SelfTest/UsageTests/ToStringWhich.tests.cpp \
#    Catch2/projects/SelfTest/UsageTests/Tricky.tests.cpp \
#    Catch2/projects/SelfTest/UsageTests/VariadicMacros.tests.cpp
