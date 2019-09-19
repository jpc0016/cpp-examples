; ModuleID = 'for_loop.cpp'
source_filename = "for_loop.cpp"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@.str = private unnamed_addr constant [38 x i8] c"The maximum value of values[] is %lu\0A\00", align 1
@.str.1 = private unnamed_addr constant [34 x i8] c"\0AThe second maximum value is %lu\0A\00", align 1
@.str.2 = private unnamed_addr constant [5 x i8] c"%zd\0A\00", align 1

; Function Attrs: noinline norecurse optnone uwtable
define dso_local i32 @main() #0 {
  %1 = alloca i32, align 4
  %2 = alloca i64, align 8
  %3 = alloca [5 x i64], align 16
  %4 = alloca i64, align 8
  %5 = alloca i64, align 8
  %6 = alloca [5 x i64], align 16
  %7 = alloca [5 x i64]*, align 8
  %8 = alloca i64*, align 8
  %9 = alloca i64*, align 8
  %10 = alloca i64, align 8
  %11 = alloca i64, align 8
  store i32 0, i32* %1, align 4
  store i64 0, i64* %2, align 8
  %12 = bitcast [5 x i64]* %3 to i8*
  call void @llvm.memset.p0i8.i64(i8* align 16 %12, i8 0, i64 40, i1 false)
  %13 = bitcast i8* %12 to [5 x i64]*
  %14 = getelementptr inbounds [5 x i64], [5 x i64]* %13, i32 0, i32 0
  store i64 10, i64* %14, align 16
  %15 = getelementptr inbounds [5 x i64], [5 x i64]* %13, i32 0, i32 1
  store i64 50, i64* %15, align 8
  %16 = getelementptr inbounds [5 x i64], [5 x i64]* %13, i32 0, i32 2
  store i64 20, i64* %16, align 16
  %17 = getelementptr inbounds [5 x i64], [5 x i64]* %13, i32 0, i32 3
  store i64 40, i64* %17, align 8
  store i64 0, i64* %4, align 8
  br label %18

; <label>:18:                                     ; preds = %32, %0
  %19 = load i64, i64* %4, align 8
  %20 = icmp ult i64 %19, 5
  br i1 %20, label %21, label %35

; <label>:21:                                     ; preds = %18
  %22 = load i64, i64* %4, align 8
  %23 = getelementptr inbounds [5 x i64], [5 x i64]* %3, i64 0, i64 %22
  %24 = load i64, i64* %23, align 8
  %25 = load i64, i64* %2, align 8
  %26 = icmp ugt i64 %24, %25
  br i1 %26, label %27, label %31

; <label>:27:                                     ; preds = %21
  %28 = load i64, i64* %4, align 8
  %29 = getelementptr inbounds [5 x i64], [5 x i64]* %3, i64 0, i64 %28
  %30 = load i64, i64* %29, align 8
  store i64 %30, i64* %2, align 8
  br label %31

; <label>:31:                                     ; preds = %27, %21
  br label %32

; <label>:32:                                     ; preds = %31
  %33 = load i64, i64* %4, align 8
  %34 = add i64 %33, 1
  store i64 %34, i64* %4, align 8
  br label %18

; <label>:35:                                     ; preds = %18
  %36 = load i64, i64* %2, align 8
  %37 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([38 x i8], [38 x i8]* @.str, i32 0, i32 0), i64 %36)
  store i64 0, i64* %5, align 8
  %38 = bitcast [5 x i64]* %6 to i8*
  call void @llvm.memset.p0i8.i64(i8* align 16 %38, i8 0, i64 40, i1 false)
  %39 = bitcast i8* %38 to [5 x i64]*
  %40 = getelementptr inbounds [5 x i64], [5 x i64]* %39, i32 0, i32 0
  store i64 10, i64* %40, align 16
  %41 = getelementptr inbounds [5 x i64], [5 x i64]* %39, i32 0, i32 1
  store i64 20, i64* %41, align 8
  %42 = getelementptr inbounds [5 x i64], [5 x i64]* %39, i32 0, i32 2
  store i64 60, i64* %42, align 16
  %43 = getelementptr inbounds [5 x i64], [5 x i64]* %39, i32 0, i32 3
  store i64 100, i64* %43, align 8
  store [5 x i64]* %6, [5 x i64]** %7, align 8
  %44 = load [5 x i64]*, [5 x i64]** %7, align 8
  %45 = getelementptr inbounds [5 x i64], [5 x i64]* %44, i32 0, i32 0
  store i64* %45, i64** %8, align 8
  %46 = load [5 x i64]*, [5 x i64]** %7, align 8
  %47 = getelementptr inbounds [5 x i64], [5 x i64]* %46, i32 0, i32 0
  %48 = getelementptr inbounds i64, i64* %47, i64 5
  store i64* %48, i64** %9, align 8
  br label %49

; <label>:49:                                     ; preds = %62, %35
  %50 = load i64*, i64** %8, align 8
  %51 = load i64*, i64** %9, align 8
  %52 = icmp ne i64* %50, %51
  br i1 %52, label %53, label %65

; <label>:53:                                     ; preds = %49
  %54 = load i64*, i64** %8, align 8
  %55 = load i64, i64* %54, align 8
  store i64 %55, i64* %10, align 8
  %56 = load i64, i64* %10, align 8
  %57 = load i64, i64* %5, align 8
  %58 = icmp ugt i64 %56, %57
  br i1 %58, label %59, label %61

; <label>:59:                                     ; preds = %53
  %60 = load i64, i64* %10, align 8
  store i64 %60, i64* %5, align 8
  br label %61

; <label>:61:                                     ; preds = %59, %53
  br label %62

; <label>:62:                                     ; preds = %61
  %63 = load i64*, i64** %8, align 8
  %64 = getelementptr inbounds i64, i64* %63, i32 1
  store i64* %64, i64** %8, align 8
  br label %49

; <label>:65:                                     ; preds = %49
  %66 = load i64, i64* %5, align 8
  %67 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([34 x i8], [34 x i8]* @.str.1, i32 0, i32 0), i64 %66)
  store i64 5, i64* %11, align 8
  %68 = load i64, i64* %11, align 8
  %69 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @.str.2, i32 0, i32 0), i64 %68)
  ret i32 0
}

; Function Attrs: argmemonly nounwind
declare void @llvm.memset.p0i8.i64(i8* nocapture writeonly, i8, i64, i1) #1

declare dso_local i32 @printf(i8*, ...) #2

attributes #0 = { noinline norecurse optnone uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { argmemonly nounwind }
attributes #2 = { "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.module.flags = !{!0}
!llvm.ident = !{!1}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{!"clang version 8.0.0-3 (tags/RELEASE_800/final)"}
